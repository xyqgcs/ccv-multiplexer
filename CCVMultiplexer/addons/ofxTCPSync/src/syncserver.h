/*#ifndef SYNCSERVER_H_INCLUDED
#define SYNCSERVER_H_INCLUDED

//#include "ofMain.h"


#include "Connection.h"

#include "ofxThread.h"
#include "ofxXmlSettings.h"
#include <vector>
#include "ofxThread.h"

class syncserver : public ofxThread {

	public:
		 syncserver();
		vector<connection> connections;
		void send(string _msg);---
		void  setup(string _fileString);--------
        void  start();-----
		bool getValue();
		void abc();

       


		bool shouldTriggerFrame;--
	
		
        void  quit();--
		void shouldContinue();----
		void setDefaults(){-----
            allconnected = false;
			//numConnectedClients = 0;
			currentFrame = 0;
			shouldTriggerFrame = false;
			running = false;
			newMessage = false;
			lastFrameTriggeredTime = 0;
			timeOfNextHeartbeat = ofGetElapsedTimef();
			heartBeatInterval = 2.0;
			numConnectedClients=0;
			numExpectedClients = 1;
			
			
        }
		void threadedFunction();
		
        void loadIniFile(string _fileString);-----
		void restartServer();
        
        void  out(string _msg);---
        void  print(string _msg);---
        void  err(string _msg);--

        void read(string response);---
		void read(string response, int i);---
       
		int getDeviceCount(){return numConnectedClients;}

		void getCalibData();
		
	    int i;
		int serverInPort;
		int serverOutPort;
	    string broadcast;
		ofxTCPServer tcpServer;
	   	ofxUDPManager udpSender;
		ofxUDPManager udpReceiver;
		bool bTCP;
		float lastFrameTriggeredTime;
		bool allconnected;
		bool running;                
		int fps;
		int numExpectedClients;
		int numConnectedClients;
		int currentFrame;
		
		

		bool newMessage;
		string currentMessage;
		float timeOfNextHeartbeat;
		float heartBeatInterval;


		void getPixels(int id, unsigned char * newFrame);
		
		ofxCvColorImage test;
		void copy();
		
	//	ofxTuioClient tuioclient;
		//TUIOListener Interface
		//void addTuioObject(TuioObject * tobj);
		//void updateTuioObject(TuioObject * tobj);
		//void removeTuioObject(TuioObject * tobj);
	
		//void addTuioCursor(TuioCursor * tcur);
		//void updateTuioCursor(TuioCursor * tcur);
		//void removeTuioCursor(TuioCursor * tcur);

		//std::list< struct connection*> tuioSources;
		
		
//private:
	//TuioTime currentTime; //namespace tuio


};
  
#endif*/
