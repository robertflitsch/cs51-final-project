#include "cv.h"
#include "highgui.h"
#include<iostream.h>
#include<math.h>


bool LightCompensation(IplImage* p,double threld);//光照补偿

bool colorBalance(IplImage* p);//色彩平衡

bool erzhihua(IplImage* pImg2);//二值化

bool xintai(IplImage* pImg2);//心态学操作

bool xintai2(IplImage* pImg2);
void searchArea(IplImage* p,int y,int x,int num);//寻找连通区域
//void hang(IplImage* p,int y,int x,int num);//寻找行列像素个数
//void lie(IplImage* p,int y,int x,int num);//寻找行列像素个数
int  delFalArea(IplImage* p,unsigned int boundnum);   //去除假区域
void LocateRect(IplImage* p,int y,int x,int num,int faceNum);
void FaceLocate(IplImage* p,int n);
bool mouthLocate(IplImage* pImg2,int n);//嘴唇提取
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	unsigned int calnum[255];//记录白色区域的的像素个数
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    IplImage* pImg1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////
	CvRect faceLocation[255];
///////////////////////////////////////////////////////////////////////////////////////////////////////
	int width;   //记录宽度
	int height;  //记录高度
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main( int argc, char** argv )
{
  IplImage* pImg; //声明IplImage指针

  //载入图像
  if( argc == 3 && (pImg = cvLoadImage( argv[1], -1)) != 0 )
    {
	  //图像的宽和长及像素总个数
	  width=pImg->width;
	  height=pImg->height;
      pImg1 = cvCreateImage(cvGetSize(pImg),pImg->depth,pImg->nChannels);
	  
	  cvCopy(pImg, pImg1, NULL);
	  
      IplImage* pImg2 = cvCreateImage(cvGetSize(pImg),pImg->depth,pImg->nChannels);
	  
	  cvCopy(pImg, pImg2, NULL);

//	  cvCvtColor( pImg, pImg2, CV_RGB2YCrCb );//空间转换

	  //是否需要光照补偿
	  if(LightCompensation(pImg2,1.008))
	  {
		  cout<<"需要光照补偿"<<endl;
		  cout<<endl;
	  }
	  else
	  {
		  cout<<"不需要光照补偿"<<endl;
		  cout<<endl;
	  }

	  //是否需要色彩平衡
	  if(colorBalance(pImg2))
	  {
		  cout<<"需要色彩修正!"<<endl;
		  cout<<endl;
	  }
	  else
	  {
		  cout<<"不需要色彩修正!"<<endl;
		  cout<<endl;
	  }

	  cvSaveImage(argv[2], pImg2);

	  //图像二值化
	  erzhihua(pImg2);
	  //膨胀和腐蚀
	  xintai(pImg2);

	  //去除较小区域
     int n=delFalArea(pImg2,800);
	  cout<<"去除较小的区域后还剩下"<<n<<"个类似脸的区域"<<endl;
	  xintai(pImg2);
     // mouthLocate(pImg2,n);
   FaceLocate(pImg2,n);
	  cvSaveImage(argv[2], pImg2);//把图像写入文件


/*	  int i,j,b;
	  int width=pImg2->width;
	int height=pImg2->height;

	for (i=0; i<height; i++)
	{
		for (j=0; j<width; j++)
		{
			b=CV_IMAGE_ELEM(pImg2,uchar,i,j*3);
			cout<<b<<" ";
		}
	}*/
   
      cvNamedWindow( "Image", 1 );//创建窗口
      cvShowImage( "Image", pImg2 );//显示图像
      
      cvWaitKey(0); //等待按键
	
      cvDestroyWindow( "Image" );//销毁窗口
      cvReleaseImage( &pImg ); //释放图像
      cvReleaseImage( &pImg2 ); //释放图像
      return 0;
    }

  return -1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool xintai(IplImage* pImg2)
{
	if(pImg2==NULL)
	{
		return false;
	}

	IplConvKernel* element=cvCreateStructuringElementEx(3,3,1,1,CV_SHAPE_ELLIPSE, NULL);
	//去除小噪点
	cvErode(pImg2,pImg2,element,1);//腐蚀
	cvDilate(pImg2,pImg2,element,1);//膨胀
    
	//分离较近的区域
	cvErode(pImg2,pImg2,element,2);//腐蚀
	cvDilate(pImg2,pImg2,element,2);//膨胀
	cvSmooth(pImg2,pImg2,CV_MEDIAN,3,0,0);//中值滤波去除孤立噪声点
	cvDilate(pImg2,pImg2,element,2);//膨胀
	cvErode(pImg2,pImg2,element,2);//腐蚀
	cvDilate(pImg2,pImg2,element,2);//膨胀
	cvErode(pImg2,pImg2,element,2);//腐蚀

	cvReleaseStructuringElement(&element);
	
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool xintai2(IplImage* pImg2)
{

	if(pImg2==NULL)
	{
		return false;
	}

	IplConvKernel* element=cvCreateStructuringElementEx(2,2,1,1,CV_SHAPE_ELLIPSE, NULL);
	cvErode(pImg2,pImg2,element,1);//腐蚀
	cvDilate(pImg2,pImg2,element,1);//膨胀
	
	cvSmooth(pImg2,pImg2,CV_MEDIAN,3,0,0);//中值滤波去除孤立噪声点

	cvDilate(pImg2,pImg2,element,5);//膨胀
	cvErode(pImg2,pImg2,element,5);//腐蚀
	
	
	cvReleaseStructuringElement(&element);
	
	return true;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool erzhihua(IplImage* pImg2)
{
	if(pImg2==NULL)
	{
		return false;
	}
	int i,j;

	float b,g,r,Cr,Cb;
	for(i=0;i<pImg2->height;i++)
	  {
		  for(j=0;j<pImg2->width;j++)
		  {
			  b=((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels];
			  g=((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels+1];
			  r=((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels+2];
			  //计算得到y，cr，cb的数值
//			  Y=(257*r+504*g+98*b)/1000+16;
			  Cr=(439*r-368*g-71*b)/1000+128;
			  Cb=(-148*r-291*g+439*b)/1000+128;
//			  cout<<Cr<<"    "<<Cb<<endl;

			  //判断条件，满足则像素设为白色，否则为黑色；
			  if(Cb>=100&&Cb<=127&&Cr>=138&&Cr<=170)
			  { 
				  ((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels]=255;
				  ((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels+1]=255;
				  ((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels+2]=255;
			  }
			  else
			  {
				  ((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels]=0;
				  ((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels+1]=0;
				  ((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels+2]=0;
			  }
//			  b=((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels];
//			  cout<<b<<" ";
		  }
	  }
	
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool LightCompensation(IplImage* p,double threld)
{
    int i,j;

	//图像的宽和长及像素总个数
//	int width=p->width;
//	int height=p->height;
	int total = width*height;

	//图像深度
	int nch1=p->nChannels;

    //比例系数
	const double k = 0.05;

	//象素个数的临界常数
	const int bordnum = 100;

	//对于过于小的图片的判断
	if(total*k < bordnum)
	{
		cout<<"图片太小"<<endl;
		return false;
	}
	//灰度级数组，初值设为零
	unsigned int scale[256];
	for(i=0;i<256;i++)
	{
		scale[i] = 0;
	}

    //图像R,G,B的分量值
	int colorr=0,colorg=0,colorb=0;
	//考察整张图片，计算亮度值Y
	for( i=0;i<height;i++)
	{
		for( j=0;j<width;j++)
			{	
				//得到rgb值
			    colorb=CV_IMAGE_ELEM( p, uchar, i, j*nch1  );
                colorg=CV_IMAGE_ELEM( p, uchar, i, j*nch1+1);
			    colorr=CV_IMAGE_ELEM( p, uchar, i, j*nch1+2);
//				cout<<colorb<<"  "<<colorg<<"  "<<colorb<<"  "<<endl;

			    //计算亮度值Y
			    int Ybright = (int)((colorr * 299 + colorg * 587 + colorb * 114)/1000.0);
			    scale[Ybright]++;
			}
	}

/*	for(i=0;i<256;i++)
	{
		cout<<scale[i]<<"   ";
	}*/


	//记录前5%亮度的个数
	int calnum =0;
	int prnumber=(int)(total*k);
	long sumYbright = 0;
	//下面的循环得到满足系数k的临界灰度级
	for(i=255;i>=0&&calnum<prnumber;i--)
	{
		
			calnum+= scale[i];
			sumYbright += scale[i]*i;	//得到满足条件的象素总的灰度值
	}

	cout<<"前5%像素的亮度总和为："<<sumYbright<<"   前5%像素的个数为："<<calnum<<endl;



	double averageYbright=((double)sumYbright)/calnum;
	//得到光线补偿的系数
	double lc = 255.0/averageYbright;
//输出系数 
	cout<<"光照补偿系数为："<<lc<<"  门限值为："<<threld<<endl;

	//判断是否需要光补偿
	if(lc<=threld)
	{
		
		//下面的循环对图象进行光线补偿
		for(i =0;i<height;i++)
			for( j=0;j<width;j++)
			{
				colorb=CV_IMAGE_ELEM( p, uchar, i, j*nch1);
				//调整
				colorb = (int)(lc*colorb);
				//临界判断
				if(colorb >255)
					colorb = 255;
				CV_IMAGE_ELEM( p, uchar, i, j*nch1)=colorb;

				colorg=CV_IMAGE_ELEM( p, uchar, i, j*nch1+1);
				//调整
				colorg = (int)(lc*colorg);
				//临界判断
				if(colorg >255)
					colorg = 255;
				CV_IMAGE_ELEM( p, uchar, i, j*nch1+1)=colorg;

				colorr=CV_IMAGE_ELEM( p, uchar, i, j*nch1+2);
				//调整
				colorr = (int)(lc*colorr);
				//临界判断
				if(colorr >255)
					colorr = 255;
				CV_IMAGE_ELEM( p, uchar, i, j*nch1+2)=colorr;
//				cout<<colorb<<"  "<<colorg<<"  "<<colorb<<"  "<<endl;
			}
       return true;

	}
	


	return false;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool colorBalance(IplImage* p)
{
	int i,j;

	//图像的宽和长及像素总个数

	int total = width*height;

	//图像深度
	int nch1=p->nChannels;

    //比例系数
	const double k = 0.1;

	//象素个数的临界常数
	const int bordnum = 500;

	//对于过于小的图片的判断
/*	if(total*k < bordnum)
	{
		cout<<"图片太小"<<endl;
		return false;
	}*/

	//灰度级数组，初值设为零
	unsigned int scale[256];
	for(i=0;i<256;i++)
	{
		scale[i] = 0;
	}

    //图像R,G,B的分量值
	int colorr=0,colorg=0,colorb=0;
	double bsum=0.0;
	double gsum=0.0;
	double rsum=0.0;
	//考察整张图片，计算亮度值Y
	int maxYbright=0;
	int Ybright=0;
	for( i=0;i<height;i++)
	{
		for( j=0;j<width;j++)
			{	
				//得到rgb值
			    colorb=CV_IMAGE_ELEM( p, uchar, i, j*nch1 );
                colorg=CV_IMAGE_ELEM( p, uchar, i, j*nch1+1 );
			    colorr=CV_IMAGE_ELEM( p, uchar, i, j*nch1+2);
//				cout<<colorb<<"  "<<colorg<<"  "<<colorb<<"  "<<endl;

			    //计算亮度值Y
			    Ybright = (colorr * 299 + colorg * 587 + colorb * 114)/1000;
				scale[Ybright]++;
			    if(Ybright>maxYbright)
				{
					maxYbright=Ybright;
				}
				bsum+=colorb/255.0;
			    gsum+=colorg/255.0;
				rsum+=colorr/255.0;
			}
	}
	int bordYbright =(int)(maxYbright*0.9);
	unsigned int sum=0;
	for(i=255;i>=bordYbright;i--)
	{
		sum+=scale[i];
	}
/*	if(sum<=bordnum)
	{
		return false;
	}*/
	double avgB=bsum/total;
	double avgG=gsum/total;
	double avgR=rsum/total;
	cout<<"B,G,R的平均值为："<<avgB<<"  "<<avgG<<"  "<<avgR<<endl;
	if((fabs(avgB-avgG)<0.2)&&(fabs(avgB-avgR)<0.2)&&(fabs(avgG-avgR)<0.2))
	{
		return false;
	}
	double avgGray=(avgB+avgG+avgR)/3;
	double kB=avgGray/avgB;
	double kG=avgGray/avgG;
	double kR=avgGray/avgR;
	int factor=255;
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			colorb=(int)(CV_IMAGE_ELEM( p, uchar, i, j*nch1 )*kB);
            colorg=(int)(CV_IMAGE_ELEM( p, uchar, i, j*nch1+1 )*kG);
			colorr=(int)(CV_IMAGE_ELEM( p, uchar, i, j*nch1+2)*kR);

			while(colorb>255||colorg>255||colorr>255)
			{
			if(colorb>255)
			{
				factor=colorb;
			}
			if(colorg>factor)
			{
				factor=colorg;
			}
			if(colorr>factor)
			{
				factor=colorr;
			}
			
				colorb=colorb*255/factor;
			    colorg=colorg*255/factor;
			    colorr=colorr*255/factor;
			}
			CV_IMAGE_ELEM( p, uchar, i, j*nch1 )=colorb;
			CV_IMAGE_ELEM( p, uchar, i, j*nch1+1 )=colorg;
			CV_IMAGE_ELEM( p, uchar, i, j*nch1+2 )=colorr;
			factor=255;
		}
	}
	return true;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int  delFalArea(IplImage* p,unsigned int boundnum)
{

	int i=0,j=0;

	//为数组赋初值，设为零；
	for(i=0;i<255;i++)
	{
		calnum[i]=0;
	}

	//图像的宽和长及像素总个数
//	int width=p->width;
//	int height=p->height;

	//避免图片压缩对像素值的影响
	for (i=0; i<height; i++)	
	  {		
		  for (j=0; j<width; j++)
		  {			
			  int b=CV_IMAGE_ELEM(p,uchar,i,j*3);
			  if(b>200)
			  {
				  CV_IMAGE_ELEM(p,uchar,i,j*3)=255;
//				  CV_IMAGE_ELEM(p,uchar,i,j*3+1)=255;
//				  CV_IMAGE_ELEM(p,uchar,i,j*3+2)=255;
			  }
			  else
			  {
				  CV_IMAGE_ELEM(p,uchar,i,j*3)=0;
//				  CV_IMAGE_ELEM(p,uchar,i,j*3+1)=0;
//				  CV_IMAGE_ELEM(p,uchar,i,j*3+2)=0;
			  }
//			  b=CV_IMAGE_ELEM(p,uchar,i,j*3);
//			  cout<<b<<" ";		
		  }	
	  }


	//记录白色区域的编号
	int num=1;
	for (i=0; i<height; i++)
	{
		for (j=0; j<width; j++)
		{
			if((CV_IMAGE_ELEM(p,uchar,i,j*3))==255)
			{	//当前点为白色，则开始递归搜索
				searchArea(p,i,j,num);
				//防止数组越界
				if(num>=255)
				{
					cout<<"记录肤色时数组越界，白色区域大于254个"<<endl;
					break;
				}
				num++;

			}
		}
	}
	cout<<num;
////////////////////////////////////////////////////////////////////////////////////////////
	int count=0;//记录去除假脸区域的个数
	int Num=num;
	for (i=1; i<num&&i<255; i++)
	{	
		//如果象素点个数小于一定数目（比如800）则把这个标志设置为0
		if (calnum[i] < boundnum)
		{
			calnum[i] = 0;
			count++;
		}
	}
			for(i=0;i<height;i++)
			{
				for(j=0;j<width;j++)
				{
					num=CV_IMAGE_ELEM(p,uchar,i,j*3);
					if(num>0&&num<255)
					{
						if(calnum[num]==0)
						{
							CV_IMAGE_ELEM(p,uchar,i,j*3)=0;
							CV_IMAGE_ELEM(p,uchar,i,j*3+1)=0;
							CV_IMAGE_ELEM(p,uchar,i,j*3+2)=0;
						}
						else 
						{
							CV_IMAGE_ELEM(p,uchar,i,j*3)=255;
							CV_IMAGE_ELEM(p,uchar,i,j*3+1)=255;
							CV_IMAGE_ELEM(p,uchar,i,j*3+2)=255;
						}
					}
				}
			}
       Num=Num-count;	
   
	   return Num;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//递归搜索，四连通；
void searchArea(IplImage* p,int y,int x,int num)
{
//	int width=p->width;
//	int height=p->height;

	//若是搜索到边界，则返回
	if(y<0||y>=height||x<0||x>=width||((CV_IMAGE_ELEM(p,uchar,y,x*3))!=255))
	{
		return ;
	}
	//若当前点是白色，则递归搜索它的上下左右四个点；
	else if((CV_IMAGE_ELEM(p,uchar,y,x*3))==255)
	{
		
		CV_IMAGE_ELEM(p,uchar,y,x*3)=num;
//		CV_IMAGE_ELEM(p,uchar,y,x*3+1)=num;
//		CV_IMAGE_ELEM(p,uchar,y,x*3+2)=num;
//				cout<<num<<" ";
		//第num个区域的像素个数加一
		calnum[num]++;
//		cout<<cal[num]<<" ";
//		int tempx;     //像素位置变量
//		int tempy;     //像素位置变量

		//递归当前点上面的点
		
		searchArea(p,y+1,x, num);//down
		searchArea(p,y-1,x, num);//up

		searchArea(p,y,x+1, num);//right
		searchArea(p,y,x-1, num);//left

	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////
void FaceLocate(IplImage* p,int n)
{	
int i=0,j=0;
IplImage* p1 = cvCreateImage(cvGetSize(p),p->depth,p->nChannels);
	  
	  cvCopy(p, p1, NULL);
	//图像的宽和长及像素总个数
//	int width=p->width;
//	int height=p->height;
	//避免图片压缩对像素值的影响
	for (i=0; i<height; i++)	
	  {		
		  for (j=0; j<width; j++)
		  {			
			  int b=CV_IMAGE_ELEM(p,uchar,i,j*3);
			  if(b>200)
			  {
				  CV_IMAGE_ELEM(p,uchar,i,j*3)=255;
//				  CV_IMAGE_ELEM(p,uchar,i,j*3+1)=255;
//				  CV_IMAGE_ELEM(p,uchar,i,j*3+2)=255;
			  }
			  else
			  {
				  CV_IMAGE_ELEM(p,uchar,i,j*3)=0;
//				  CV_IMAGE_ELEM(p,uchar,i,j*3+1)=0;
//				  CV_IMAGE_ELEM(p,uchar,i,j*3+2)=0;
			  }
//			  b=CV_IMAGE_ELEM(p,uchar,i,j*3);
//			  cout<<b<<" ";		
		  }	
	  }
	
	//人脸数目初始化为0
int faceNum =0;
	for(int k=0; k<n; k++)
	{	
		//初始化区域
		faceLocation[k].y = -1;
		faceLocation[k].height = height;
		faceLocation[k].x = -1;
		faceLocation[k].width = width;
	}

	for(i=0; i<height; i++)
		for (j=0; j<width; j++)
		{	
			int num;
			//当前点的数值
			num =CV_IMAGE_ELEM(p,uchar,i,j*3);
			if (num !=0)//不是黑色
			{	
				//递归计算
				LocateRect( p,i,j,num, faceNum);
				faceNum++;
			}
		}
	//图像还原
    cvCopy(pImg1, p, NULL);
   float chang[255],kuan[255];
   for (i=0; i<faceNum; i++)
   {
	   chang[i]=kuan[i]=0.0;
       chang[i]=faceLocation[i].y-faceLocation[i].height;
	   kuan[i]=faceLocation[i].x-faceLocation[i].width;
       cout<<i<<"个"<<chang[i]/kuan[i]<<endl;
   }
   for (k=0; k<faceNum; k++)
	   if((chang[k]/kuan[k])<2.5&&(chang[k]/kuan[k])>0.8)
	   { 
		   if((chang[k]/kuan[k])>1.8)
             faceLocation[k].y=faceLocation[k].height+1.5*kuan[k];
		   for (j=faceLocation[k].height; j<faceLocation[k].y; j++)
		{	
			//把得到的人脸区域用绿色矩形标注，处理竖直的两条矩形边
			
			CV_IMAGE_ELEM(p,uchar,j,faceLocation[k].width*3) = 0;
			CV_IMAGE_ELEM(p,uchar,j,faceLocation[k].width*3+1) = 255;
			CV_IMAGE_ELEM(p,uchar,j,faceLocation[k].width*3+2) = 0;
			
			CV_IMAGE_ELEM(p,uchar,j,faceLocation[k].x*3) = 0;
			CV_IMAGE_ELEM(p,uchar,j,faceLocation[k].x*3+1) = 255;
			CV_IMAGE_ELEM(p,uchar,j,faceLocation[k].x*3+2) = 0;

		}
	   }
		for (k=0; k<faceNum; k++)
			if((chang[k]/kuan[k])<2.5&&(chang[k]/kuan[k])>0.8)
			{ 
				if((chang[k]/kuan[k])>1.8)
                  faceLocation[k].y=faceLocation[k].height+1.5*kuan[k];
		            for (j=faceLocation[k].width; j<faceLocation[k].x; j++)
					{	
			//处理水平的两条矩形边
		             	CV_IMAGE_ELEM(p,uchar,faceLocation[k].height,j*3) = 0;
			            CV_IMAGE_ELEM(p,uchar,faceLocation[k].height,j*3+1) =255;
			            CV_IMAGE_ELEM(p,uchar,faceLocation[k].height,j*3+2) = 0;
			            CV_IMAGE_ELEM(p,uchar,faceLocation[k].y,j*3) = 0;
			            CV_IMAGE_ELEM(p,uchar,faceLocation[k].y,j*3+1) = 255;
		                CV_IMAGE_ELEM(p,uchar,faceLocation[k].y,j*3+2) = 0;

					} 
			}
/*for (k=0; k<faceNum; k++)
  if((chang[k]/kuan[k])>2.5||(chang[k]/kuan[k])<0.8)
  {
	  for (i=faceLocation[k].height; i<=faceLocation[k].y; i++)
			
			for (j=faceLocation[k].width; j<=faceLocation[k].x; j++)
			{
			CV_IMAGE_ELEM(p,uchar,i,j*3) = 0;
			CV_IMAGE_ELEM(p,uchar,i,j*3+1) = 0;
			CV_IMAGE_ELEM(p,uchar,i,j*3+2) = 0;

			}
  }*/
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LocateRect(IplImage* p,int y,int x,int num,int faceNum)
{	
	if(CV_IMAGE_ELEM(p,uchar,y,x*3) == num)
	{	
		//更改颜色为黑色
		CV_IMAGE_ELEM(p,uchar,y,x*3) = 0;
		CV_IMAGE_ELEM(p,uchar,y,x*3+1) = 0;
		CV_IMAGE_ELEM(p,uchar,y,x*3+2) = 0;
		//修改矩形的上下左右四个点位置
		if(faceLocation[faceNum].y < y)
		{
			faceLocation[faceNum].y = y;
		}

		if(faceLocation[faceNum].height > y)
		{
			faceLocation[faceNum].height = y;
		}

		if(faceLocation[faceNum].x < x)
		{
		faceLocation[faceNum].x = x;
		}

		if(faceLocation[faceNum].width > x)
		{
			faceLocation[faceNum].width = x;
		}
		//上下左右调用本函数进行区域判定
		LocateRect(p, y-1, x, num,faceNum);
		LocateRect(p, y+1, x, num, faceNum);
		LocateRect(p, y, x-1, num, faceNum);
		LocateRect(p, y, x+1, num, faceNum);
	}
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool mouthLocate(IplImage* pImg2,int n)
{
int i=0,j=0;
//IplImage* p1 = cvCreateImage(cvGetSize(p),p->depth,p->nChannels);
	  
	  //cvCopy(p, p1, NULL);
	//图像的宽和长及像素总个数
//	int width=pImg2->width;
//	int height=pImg2->height;
	//避免图片压缩对像素值的影响
	for (i=0; i<height; i++)	
	  {		
		  for (j=0; j<width; j++)
		  {			
			  int b=CV_IMAGE_ELEM(pImg2,uchar,i,j*3);
			  if(b>200)
			  {
				  CV_IMAGE_ELEM(pImg2,uchar,i,j*3)=255;
//				  CV_IMAGE_ELEM(p,uchar,i,j*3+1)=255;
//				  CV_IMAGE_ELEM(p,uchar,i,j*3+2)=255;
			  }
			  else
			  {
				  CV_IMAGE_ELEM(pImg2,uchar,i,j*3)=0;
//				  CV_IMAGE_ELEM(p,uchar,i,j*3+1)=0;
//				  CV_IMAGE_ELEM(p,uchar,i,j*3+2)=0;
			  }
//			  b=CV_IMAGE_ELEM(p,uchar,i,j*3);
//			  cout<<b<<" ";		
		  }	
	  }
	
	//人脸数目初始化为0
int faceNum =0;
	for(int k=0; k<n; k++)
	{	
		//初始化区域
		faceLocation[k].y = -1;
		faceLocation[k].height = height;
		faceLocation[k].x = -1;
		faceLocation[k].width = width;
	}

	for(i=0; i<height; i++)
		for (j=0; j<width; j++)
		{	
			int num;
			//当前点的数值
			num =CV_IMAGE_ELEM(pImg2,uchar,i,j*3);
			if (num !=0)//不是黑色
			{	
				//递归计算
				LocateRect( pImg2,i,j,num, faceNum);
				faceNum++;
			}
		}
	//图像还原

		int b,g,r;
		int Cr,Cb;
		cvCopy(pImg1,pImg2, NULL);

		LightCompensation(pImg2,1.008);
		colorBalance(pImg2);
		for(int t=0;t<faceNum;t++)
		{
			for(i=faceLocation[t].height;i<=faceLocation[t].y;i++)
			{
				for(j=faceLocation[t].width;j<=faceLocation[t].x;j++)
				{
					b=((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels];
					g=((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels+1];
					r=((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels+2];
					//计算得到y，cr，cb的数值
					//Y=(257*r+504*g+98*b)/1000+16;
					Cr=(439*r-368*g-71*b)/1000+128;
					Cb=(-148*r-291*g+439*b)/1000+128;
					
					if(Cr>152&&Cr<162&&Cb>113&&Cb<123)
					{
						((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels]=255;
						((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels+1]=255;
						((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels+2]=255;
					}
					else
					{
						((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels]=0;
						((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels+1]=0;
						((uchar*)(pImg2->imageData+pImg2->widthStep*i))[j*pImg2->nChannels+2]=0;
					}
				}
			}
		}
		xintai(pImg2);
		return true;
}