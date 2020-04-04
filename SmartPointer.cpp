#include <assert.h>
#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
class SmartPointer{
    public:
        SmartPointer(T * ptr = 0) : ptr_(ptr){
            if(ptr_ != 0)
                cnt_ = new size_t(1);
            else
                cnt_ = NULL;
        }

        SmartPointer(const SmartPointer& src){
            if(src.ptr_ != NULL){
                ptr_ = src.ptr_;
                cnt_ = src.cnt_;
                *cnt_++;
            }
            else
            {
                ptr_ = NULL;
                cnt_ = NULL;
            }
        }

        SmartPointer& operator=(const SmartPointer& src){
            if(ptr_ != src.ptr_){
                releaseCnt();
                if(src.ptr_ != NULL){
                    ptr_ = src.ptr_;
                    cnt_ = src.cnt_;
                    *cnt_++;      
                }
                else{
                    ptr_ = NULL;
                    cnt_ = NULL;                    
                }
            }
            return *this;
        }

        ~SmartPointer(){
            releaseCnt();
        }

        T& operator*(){
            assert(ptr_ != NULL);
            return *ptr_;
        }

        T* operator->(){
            assert(ptr_ != NULL);
            return ptr_;
        }

        size_t getCnt(){
            if(cnt_ != NULL)
                return *cnt_;
            else
                return 0;
        }
    private:
        T * ptr_;
        size_t * cnt_;
        void releaseCnt(){
            if(ptr_){
                (*cnt_)--;
                if(*cnt_ == 0){
                    delete ptr_;
                    delete cnt_;
                }
            }
        }
};




int main(){
    //test1 
    cout << "start test1:"<<endl;
    SmartPointer<int> s1(new int(1));
    SmartPointer<int> s2 = s1;
    cout << "s1.cnt: " << s1.getCnt() <<endl;
    cout << "s2.cnt: " << s2.getCnt() <<endl;    
    cout << "end test1:"<<endl;

    //test2
    cout << "start test2:"<<endl;
    SmartPointer<int> s3;
    SmartPointer<int> s4(new int(1));
    s3 = s4;
    cout << "s3.cnt: " << s3.getCnt() <<endl;
    cout << "s4.cnt: " << s4.getCnt() <<endl;     
    cout << "end test2:"<<endl;
    return 0;
}