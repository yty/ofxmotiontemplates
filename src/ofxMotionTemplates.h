#ifndef OFXMOTIONTEMPLATES_H
#define OFXMOTIONTEMPLATES_H

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofxMotionTemplates
{
    public:
        ofxMotionTemplates();
        virtual ~ofxMotionTemplates();

        void setup(int w, int h, int thr=0, double sec=1);
        void update(IplImage * img);
        void draw();
        bool isMainGestureDone();

        double MHI_DURATION;
        double MAX_TIME_DELTA;
        double MIN_TIME_DELTA;

        int N;

        IplImage ** buff;
        int last;

        IplImage * mhi;
        IplImage * orient;
        IplImage * mask;
        IplImage * segmask;

        CvMemStorage * storage;

        CvSize size;

        ofxCvColorImage motion;

        int diff_threshold;

        typedef struct{
            int x;
            int y;
            float dim;
            float angle;
        }moTemp;

        moTemp mainMotion;
        vector <moTemp> motionFrag;
        int oldMain;
    protected:
    private:
};

#endif // OFXMOTIONTEMPLATES_H
