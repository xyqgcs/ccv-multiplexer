#include "ofxIPImage.h"

ofxIPImage::ofxIPImage(){
	servercopy =NULL;
	x=0;
//	image.allocate(320,240);
	//fbo.allocate(320,240,GL_RGB);
	//cout<<"FBO Allocate"<<endl;
	/*height = 240;
	width=320;
	blobImage.allocate(width, height); //main Image that'll be processed.
	blackImage.allocate(width, height);
	blobImageBw.allocate(width, height);
	testImage.allocate(width, .height,OF_IMAGE_GRAYSCALE);
	blackPixels			= new unsigned char [width* height]; //empty the image*/
}

ofxIPImage::~ofxIPImage()
{
	deinitializeCamera();
//	stopThread();
}

void ofxIPImage::callSettingsDialog()
{
}

CAMERA_BASE_FEATURE* ofxIPImage::getSupportedFeatures(int* featuresCount)
{
	*featuresCount = 0;
	CAMERA_BASE_FEATURE* features = (CAMERA_BASE_FEATURE*)malloc(*featuresCount * sizeof(CAMERA_BASE_FEATURE));
	return features;
}

int ofxIPImage::getCameraBaseCount()
{
	ofxXmlSettings* xml = new ofxXmlSettings();
	 if (xml->loadFile("xml/TCPSyncServer.xml"))
        cout<<"ERROR loading XML file!";
	else
		cout<<"Xml Loaded successfully";
	int num = xml->getValue("settings:numclients", 1, 0);
	cout<<"clients"<<num;
	delete xml;
	xml = NULL;
	return num;
	
}

GUID* ofxIPImage::getBaseCameraGuids(int* camCount)
{
	*camCount = getCameraBaseCount();
	GUID* guids = (GUID*)malloc(*camCount * sizeof(GUID));
	for (int i=0;i<*camCount;i++)
	{
		GUID tempGuid;
		tempGuid.Data1 = i;
		tempGuid.Data2 = tempGuid.Data3 = 0;
		memset(tempGuid.Data4,0,8*sizeof(unsigned char));
		guids[i] = tempGuid;
	}
	return guids;
}

void ofxIPImage::setCameraType()
{
	cameraType = IPIMAGE;
	cameraTypeName = "IPIMAGE";
}

void ofxIPImage::setCameraFeature(CAMERA_BASE_FEATURE featureCode,int firstValue,int secondValue,bool isAuto,bool isEnabled)
{
}

void ofxIPImage::getCameraFeature(CAMERA_BASE_FEATURE featureCode,int* firstValue,int* secondValue, bool* isAuto, bool* isEnabled,int* minValue,int* maxValue)
{
}

void ofxIPImage::getNewFrame(unsigned char* newFrame)
{	 
	
	
	//cout<<"Number of Points"<<servercopy->connections.size()<<endl;
	

	
		
	//memcpy((void*)newFrame,(unsigned char*)image.getPixels(),320*240*3*sizeof(unsigned char));


	
	/*cvRectangle(connections[0].blobImage.getCvImage(),cvPoint(0,0),cvPoint(320,240),cvScalar(0,0,0),-1);
	memcpy((void*)newFrame,(unsigned char*)connections[0].blobImage.getPixels(),320*240*3*sizeof(unsigned char));
	if(connections[0].ready)
	memcpy((void*)newFrame,(unsigned char*)connections[0].blobImage.getPixels(),320*240*3*sizeof(unsigned char));*/
	//getPixels(guid.Data1,newFrame);
	
	//ofxCvColorImage test;
	//image.allocate(320,240);
	//cout<<"points value"<<connections[0]->points.size()<<endl;
	//cout<<"GUID number"<<guid.Data1<<endl;
	//EnterCriticalSection(&criticalSection); 
	//cvRectangle(image.getCvImage(),cvPoint(0,0),cvPoint(320,240),cvScalar(0,0,0),-1);
	//LeaveCriticalSection(&criticalSection); 
	//if(servercopy->connections[guid.Data1]->points.size()!=0)
	//if(x/2!=0)
	//{
		//cvRectangle(image.getCvImage(),cvPoint(0,0),cvPoint(320,240),cvScalar(0,0,0),-1);
		//for(std::vector<ofPoint>::iterator it = connections[guid.Data1]->points.begin();it != connections[guid.Data1]->points.end();it++)
		//{
			//cvCircle(image.getCvImage(),cvPoint((*it).x ,(*it).y),30,cvScalar(255,255,255),-1);
		//cvCircle(image.getCvImage(),cvPoint(70 ,40),30,cvScalar(255,255,255),-1);
		//}
		//cout<<"ENTER"<<endl;
		
	//}
	//else
	//{
		//cvRectangle(image.getCvImage(),	cvPoint(0,0),cvPoint(320,240),cvScalar(255,255,255),-1);
		//cvCircle(image.getCvImage(),cvPoint(70 ,40),30,cvScalar(0,0,0),-1);
		//cout<<"Outside"<<endl;
		
	//}
	cout<<"get new frae"<<endl;
	if(servercopy->connections[guid.Data1]->points.size()!=0)
	{
		for(std::vector<ofPoint>::iterator it = servercopy->connections[guid.Data1]->points.begin();it != servercopy->connections[guid.Data1]->points.end();it++)
		{
			cout<<"Node:"<<guid.Data1<<"Points:"<<(*it).x<<","<<(*it).y<<endl;
		}
	}
	else
		cout<<"Node:"<<guid.Data1<<"No points recieved"<<endl;
			//cvCircle(image.getCvImage(),cvPoint((*it).x ,(*it).y),30,cvScalar(255,255,255),-1);
		//cvCircle(image.getCvImage(),cvPoint(70 ,40),30,cvScalar(255,255,255),-1);
		//}
	//memcpy((void*)newFrame,(unsigned char*)servercopy->connections[guid.Data1]->test.getPixels(),320*240*3*sizeof(unsigned char));
	servercopy->connections[guid.Data1]->points.clear();
	
	x++;
	
}

void ofxIPImage::cameraInitializationLogic()
{
	
	
}

void ofxIPImage::cameraDeinitializationLogic()
{
}

