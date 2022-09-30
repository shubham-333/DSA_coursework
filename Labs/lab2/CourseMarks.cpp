#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Course{
private:
    vector<int>courseMarks;
public:
    string name;
    string IC;
    int numberOfStudents;
    int maxMarks;
    Course(string nam, string ic, int nos,int mm){
        name=nam;
        IC=ic;
        numberOfStudents=nos;
        maxMarks=mm;
        
    }
    vector<int> getMarks(){
        return courseMarks;
    }
    void setCourseMarks(vector<int>&v){
        courseMarks=v;
    }
    bool evaluateAnswer(int givenAnswer, int expectedAnswer){
        return (givenAnswer ==expectedAnswer);  
    }
    bool evaluateAnswer(float givenAnswer, float expectedAnswer){
        return (givenAnswer ==expectedAnswer);  
    }
    bool evaluateAnswer(string givenAnswer, string expectedAnswer){
        return (givenAnswer ==expectedAnswer);  
    }
    
};

class Lab: public Course{
private:
    vector<int> labMarks;
public:
    void setLabMarks(vector<int>&v){
        labMarks=v;
    }
    int countNC(int minMarks){
        int nc=0;
        int l=labMarks.size();
        vector<int> v=this->getMarks();
        for(int i=0;i<l;i++) if(labMarks[i]+v[i]<minMarks) nc++;
        return nc;        
    }
};

int main() {
    // Your code goes here;

    return 0;
}