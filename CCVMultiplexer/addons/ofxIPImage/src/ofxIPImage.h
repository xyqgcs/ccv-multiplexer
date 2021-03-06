#ifndef OFXIPIMAGE_H_INCLUDED
#define OFXIPIMAGE_H_INCLUDED

#include "ofxCameraBase.h"
#include "syncserver.h"
//#include "connection.h"


class ofxIPImage : public ofxCameraBase{

public:
	ofxIPImage();
	syncserver* servercopy;
	ofxIPImage(syncserver* copy)
	{
		servercopy=copy;
	}
	~ofxIPImage();
	int getCameraBaseCount();
	void callSettingsDialog();
	CAMERA_BASE_FEATURE* getSupportedFeatures(int* featuresCount);
	void setCameraFeature(CAMERA_BASE_FEATURE featureCode,int firstValue,int secondValue,bool isAuto,bool isEnabled);
	void getCameraFeature(CAMERA_BASE_FEATURE featureCode,int* firstValue,int* secondValue, bool* isAuto, bool* isEnabled,int* minValue,int* maxValue);
	GUID* getBaseCameraGuids(int* camCount);

protected:
	void getNewFrame(unsigned char* newFrame);
	void cameraInitializationLogic();
	void cameraDeinitializationLogic();
	void setCameraType();
	
private:
	static DWORD WINAPI SettingsThread(LPVOID instance);
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	void StartSettingsDialog();
	HANDLE settingsGUIThread;
	bool isSettedDefaultSettings;
	
	
	
	

};


#endif



