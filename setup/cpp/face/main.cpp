#include "cv.h"
#include "highgui.h"
#include<iostream.h>
#include<math.h>


bool LightCompensation(IplImage* p,double threld);//���ղ���

bool colorBalance(IplImage* p);//ɫ��ƽ��

bool erzhihua(IplImage* pImg2);//��ֵ��

bool xintai(IplImage* pImg2);//��̬ѧ����

bool xintai2(IplImage* pImg2);
void searchArea(IplImage* p,int y,int x,int num);//Ѱ����ͨ����
//void hang(IplImage* p,int y,int x,int num);//Ѱ���������ظ���
//void lie(IplImage* p,int y,int x,int num);//Ѱ���������ظ���
int  delFalArea(IplImage* p,unsigned int boundnum);   //ȥ��������
void LocateRect(IplImage* p,int y,int x,int num,int faceNum);
void FaceLocate(IplImage* p,int n);
bool mouthLocate(IplImage* pImg2,int n);//�촽��ȡ
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	unsigned int calnum[255];//��¼��ɫ����ĵ����ظ���
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    IplImage* pImg1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////
	CvRect faceLocation[255];
///////////////////////////////////////////////////////////////////////////////////////////////////////
	int width;   //��¼���
	int height;  //��¼�߶�
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main( int argc, char** argv )
{
  IplImage* pImg; //����IplImageָ��

  //����ͼ��
  if( argc == 3 && (pImg = cvLoadImage( argv[1], -1)) != 0 )
    {
	  //ͼ��Ŀ�ͳ��������ܸ���
	  width=pImg->width;
	  height=pImg->height;
      pImg1 = cvCreateImage(cvGetSize(pImg),pImg->depth,pImg->nChannels);
	  
	  cvCopy(pImg, pImg1, NULL);
	  
      IplImage* pImg2 = cvCreateImage(cvGetSize(pImg),pImg->depth,pImg->nChannels);
	  
	  cvCopy(pImg, pImg2, NULL);

//	  cvCvtColor( pImg, pImg2, CV_RGB2YCrCb );//�ռ�ת��

	  //�Ƿ���Ҫ���ղ���
	  if(LightCompensation(pImg2,1.008))
	  {
		  cout<<"��Ҫ���ղ���"<<endl;
		  cout<<endl;
	  }
	  else
	  {
		  cout<<"����Ҫ���ղ���"<<endl;
		  cout<<endl;
	  }

	  //�Ƿ���Ҫɫ��ƽ��
	  if(colorBalance(pImg2))
	  {
		  cout<<"��Ҫɫ������!"<<endl;
		  cout<<endl;
	  }
	  else
	  {
		  cout<<"����Ҫɫ������!"<<endl;
		  cout<<endl;
	  }

	  cvSaveImage(argv[2], pImg2);

	  //ͼ���ֵ��
	  erzhihua(pImg2);
	  //���ͺ͸�ʴ
	  xintai(pImg2);

	  //ȥ����С����
     int n=delFalArea(pImg2,800);
	  cout<<"ȥ����С�������ʣ��"<<n<<"��������������"<<endl;
	  xintai(pImg2);
     // mouthLocate(pImg2,n);
   FaceLocate(pImg2,n);
	  cvSaveImage(argv[2], pImg2);//��ͼ��д���ļ�


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
   
      cvNamedWindow( "Image", 1 );//��������
      cvShowImage( "Image", pImg2 );//��ʾͼ��
      
      cvWaitKey(0); //�ȴ�����
	
      cvDestroyWindow( "Image" );//���ٴ���
      cvReleaseImage( &pImg ); //�ͷ�ͼ��
      cvReleaseImage( &pImg2 ); //�ͷ�ͼ��
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
	//ȥ��С���
	cvErode(pImg2,pImg2,element,1);//��ʴ
	cvDilate(pImg2,pImg2,element,1);//����
    
	//����Ͻ�������
	cvErode(pImg2,pImg2,element,2);//��ʴ
	cvDilate(pImg2,pImg2,element,2);//����
	cvSmooth(pImg2,pImg2,CV_MEDIAN,3,0,0);//��ֵ�˲�ȥ������������
	cvDilate(pImg2,pImg2,element,2);//����
	cvErode(pImg2,pImg2,element,2);//��ʴ
	cvDilate(pImg2,pImg2,element,2);//����
	cvErode(pImg2,pImg2,element,2);//��ʴ

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
	cvErode(pImg2,pImg2,element,1);//��ʴ
	cvDilate(pImg2,pImg2,element,1);//����
	
	cvSmooth(pImg2,pImg2,CV_MEDIAN,3,0,0);//��ֵ�˲�ȥ������������

	cvDilate(pImg2,pImg2,element,5);//����
	cvErode(pImg2,pImg2,element,5);//��ʴ
	
	
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
			  //����õ�y��cr��cb����ֵ
//			  Y=(257*r+504*g+98*b)/1000+16;
			  Cr=(439*r-368*g-71*b)/1000+128;
			  Cb=(-148*r-291*g+439*b)/1000+128;
//			  cout<<Cr<<"    "<<Cb<<endl;

			  //�ж�������������������Ϊ��ɫ������Ϊ��ɫ��
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

	//ͼ��Ŀ�ͳ��������ܸ���
//	int width=p->width;
//	int height=p->height;
	int total = width*height;

	//ͼ�����
	int nch1=p->nChannels;

    //����ϵ��
	const double k = 0.05;

	//���ظ������ٽ糣��
	const int bordnum = 100;

	//���ڹ���С��ͼƬ���ж�
	if(total*k < bordnum)
	{
		cout<<"ͼƬ̫С"<<endl;
		return false;
	}
	//�Ҷȼ����飬��ֵ��Ϊ��
	unsigned int scale[256];
	for(i=0;i<256;i++)
	{
		scale[i] = 0;
	}

    //ͼ��R,G,B�ķ���ֵ
	int colorr=0,colorg=0,colorb=0;
	//��������ͼƬ����������ֵY
	for( i=0;i<height;i++)
	{
		for( j=0;j<width;j++)
			{	
				//�õ�rgbֵ
			    colorb=CV_IMAGE_ELEM( p, uchar, i, j*nch1  );
                colorg=CV_IMAGE_ELEM( p, uchar, i, j*nch1+1);
			    colorr=CV_IMAGE_ELEM( p, uchar, i, j*nch1+2);
//				cout<<colorb<<"  "<<colorg<<"  "<<colorb<<"  "<<endl;

			    //��������ֵY
			    int Ybright = (int)((colorr * 299 + colorg * 587 + colorb * 114)/1000.0);
			    scale[Ybright]++;
			}
	}

/*	for(i=0;i<256;i++)
	{
		cout<<scale[i]<<"   ";
	}*/


	//��¼ǰ5%���ȵĸ���
	int calnum =0;
	int prnumber=(int)(total*k);
	long sumYbright = 0;
	//�����ѭ���õ�����ϵ��k���ٽ�Ҷȼ�
	for(i=255;i>=0&&calnum<prnumber;i--)
	{
		
			calnum+= scale[i];
			sumYbright += scale[i]*i;	//�õ����������������ܵĻҶ�ֵ
	}

	cout<<"ǰ5%���ص������ܺ�Ϊ��"<<sumYbright<<"   ǰ5%���صĸ���Ϊ��"<<calnum<<endl;



	double averageYbright=((double)sumYbright)/calnum;
	//�õ����߲�����ϵ��
	double lc = 255.0/averageYbright;
//���ϵ�� 
	cout<<"���ղ���ϵ��Ϊ��"<<lc<<"  ����ֵΪ��"<<threld<<endl;

	//�ж��Ƿ���Ҫ�ⲹ��
	if(lc<=threld)
	{
		
		//�����ѭ����ͼ����й��߲���
		for(i =0;i<height;i++)
			for( j=0;j<width;j++)
			{
				colorb=CV_IMAGE_ELEM( p, uchar, i, j*nch1);
				//����
				colorb = (int)(lc*colorb);
				//�ٽ��ж�
				if(colorb >255)
					colorb = 255;
				CV_IMAGE_ELEM( p, uchar, i, j*nch1)=colorb;

				colorg=CV_IMAGE_ELEM( p, uchar, i, j*nch1+1);
				//����
				colorg = (int)(lc*colorg);
				//�ٽ��ж�
				if(colorg >255)
					colorg = 255;
				CV_IMAGE_ELEM( p, uchar, i, j*nch1+1)=colorg;

				colorr=CV_IMAGE_ELEM( p, uchar, i, j*nch1+2);
				//����
				colorr = (int)(lc*colorr);
				//�ٽ��ж�
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

	//ͼ��Ŀ�ͳ��������ܸ���

	int total = width*height;

	//ͼ�����
	int nch1=p->nChannels;

    //����ϵ��
	const double k = 0.1;

	//���ظ������ٽ糣��
	const int bordnum = 500;

	//���ڹ���С��ͼƬ���ж�
/*	if(total*k < bordnum)
	{
		cout<<"ͼƬ̫С"<<endl;
		return false;
	}*/

	//�Ҷȼ����飬��ֵ��Ϊ��
	unsigned int scale[256];
	for(i=0;i<256;i++)
	{
		scale[i] = 0;
	}

    //ͼ��R,G,B�ķ���ֵ
	int colorr=0,colorg=0,colorb=0;
	double bsum=0.0;
	double gsum=0.0;
	double rsum=0.0;
	//��������ͼƬ����������ֵY
	int maxYbright=0;
	int Ybright=0;
	for( i=0;i<height;i++)
	{
		for( j=0;j<width;j++)
			{	
				//�õ�rgbֵ
			    colorb=CV_IMAGE_ELEM( p, uchar, i, j*nch1 );
                colorg=CV_IMAGE_ELEM( p, uchar, i, j*nch1+1 );
			    colorr=CV_IMAGE_ELEM( p, uchar, i, j*nch1+2);
//				cout<<colorb<<"  "<<colorg<<"  "<<colorb<<"  "<<endl;

			    //��������ֵY
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
	cout<<"B,G,R��ƽ��ֵΪ��"<<avgB<<"  "<<avgG<<"  "<<avgR<<endl;
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

	//Ϊ���鸳��ֵ����Ϊ�㣻
	for(i=0;i<255;i++)
	{
		calnum[i]=0;
	}

	//ͼ��Ŀ�ͳ��������ܸ���
//	int width=p->width;
//	int height=p->height;

	//����ͼƬѹ��������ֵ��Ӱ��
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


	//��¼��ɫ����ı��
	int num=1;
	for (i=0; i<height; i++)
	{
		for (j=0; j<width; j++)
		{
			if((CV_IMAGE_ELEM(p,uchar,i,j*3))==255)
			{	//��ǰ��Ϊ��ɫ����ʼ�ݹ�����
				searchArea(p,i,j,num);
				//��ֹ����Խ��
				if(num>=255)
				{
					cout<<"��¼��ɫʱ����Խ�磬��ɫ�������254��"<<endl;
					break;
				}
				num++;

			}
		}
	}
	cout<<num;
////////////////////////////////////////////////////////////////////////////////////////////
	int count=0;//��¼ȥ����������ĸ���
	int Num=num;
	for (i=1; i<num&&i<255; i++)
	{	
		//������ص����С��һ����Ŀ������800����������־����Ϊ0
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
//�ݹ�����������ͨ��
void searchArea(IplImage* p,int y,int x,int num)
{
//	int width=p->width;
//	int height=p->height;

	//�����������߽磬�򷵻�
	if(y<0||y>=height||x<0||x>=width||((CV_IMAGE_ELEM(p,uchar,y,x*3))!=255))
	{
		return ;
	}
	//����ǰ���ǰ�ɫ����ݹ������������������ĸ��㣻
	else if((CV_IMAGE_ELEM(p,uchar,y,x*3))==255)
	{
		
		CV_IMAGE_ELEM(p,uchar,y,x*3)=num;
//		CV_IMAGE_ELEM(p,uchar,y,x*3+1)=num;
//		CV_IMAGE_ELEM(p,uchar,y,x*3+2)=num;
//				cout<<num<<" ";
		//��num����������ظ�����һ
		calnum[num]++;
//		cout<<cal[num]<<" ";
//		int tempx;     //����λ�ñ���
//		int tempy;     //����λ�ñ���

		//�ݹ鵱ǰ������ĵ�
		
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
	//ͼ��Ŀ�ͳ��������ܸ���
//	int width=p->width;
//	int height=p->height;
	//����ͼƬѹ��������ֵ��Ӱ��
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
	
	//������Ŀ��ʼ��Ϊ0
int faceNum =0;
	for(int k=0; k<n; k++)
	{	
		//��ʼ������
		faceLocation[k].y = -1;
		faceLocation[k].height = height;
		faceLocation[k].x = -1;
		faceLocation[k].width = width;
	}

	for(i=0; i<height; i++)
		for (j=0; j<width; j++)
		{	
			int num;
			//��ǰ�����ֵ
			num =CV_IMAGE_ELEM(p,uchar,i,j*3);
			if (num !=0)//���Ǻ�ɫ
			{	
				//�ݹ����
				LocateRect( p,i,j,num, faceNum);
				faceNum++;
			}
		}
	//ͼ��ԭ
    cvCopy(pImg1, p, NULL);
   float chang[255],kuan[255];
   for (i=0; i<faceNum; i++)
   {
	   chang[i]=kuan[i]=0.0;
       chang[i]=faceLocation[i].y-faceLocation[i].height;
	   kuan[i]=faceLocation[i].x-faceLocation[i].width;
       cout<<i<<"��"<<chang[i]/kuan[i]<<endl;
   }
   for (k=0; k<faceNum; k++)
	   if((chang[k]/kuan[k])<2.5&&(chang[k]/kuan[k])>0.8)
	   { 
		   if((chang[k]/kuan[k])>1.8)
             faceLocation[k].y=faceLocation[k].height+1.5*kuan[k];
		   for (j=faceLocation[k].height; j<faceLocation[k].y; j++)
		{	
			//�ѵõ���������������ɫ���α�ע��������ֱ���������α�
			
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
			//����ˮƽ���������α�
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
		//������ɫΪ��ɫ
		CV_IMAGE_ELEM(p,uchar,y,x*3) = 0;
		CV_IMAGE_ELEM(p,uchar,y,x*3+1) = 0;
		CV_IMAGE_ELEM(p,uchar,y,x*3+2) = 0;
		//�޸ľ��ε����������ĸ���λ��
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
		//�������ҵ��ñ��������������ж�
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
	//ͼ��Ŀ�ͳ��������ܸ���
//	int width=pImg2->width;
//	int height=pImg2->height;
	//����ͼƬѹ��������ֵ��Ӱ��
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
	
	//������Ŀ��ʼ��Ϊ0
int faceNum =0;
	for(int k=0; k<n; k++)
	{	
		//��ʼ������
		faceLocation[k].y = -1;
		faceLocation[k].height = height;
		faceLocation[k].x = -1;
		faceLocation[k].width = width;
	}

	for(i=0; i<height; i++)
		for (j=0; j<width; j++)
		{	
			int num;
			//��ǰ�����ֵ
			num =CV_IMAGE_ELEM(pImg2,uchar,i,j*3);
			if (num !=0)//���Ǻ�ɫ
			{	
				//�ݹ����
				LocateRect( pImg2,i,j,num, faceNum);
				faceNum++;
			}
		}
	//ͼ��ԭ

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
					//����õ�y��cr��cb����ֵ
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