#ifndef __MiniFramework_h__
#define __MiniFramework_h__

#include <vector>
#include <algorithm>

template <typename V>
class IInputProcessor
{
public:
    virtual void process(const V& obj) = 0;
};


template <typename T>
class Convey
{
public:
    virtual ~Convey(void){}

    void addNextProcessor(IInputProcessor<T> * inputProcessor ){
        inputProcessors_.push_back(inputProcessor);
    }

    
    void propagate(const T& good){
        // currently it's not portable
        // this iteration can replace with general for 
        std::for_each(inputProcessors_.begin(), inputProcessors_.end(), [&](IInputProcessor<T> * inputProcessor){
            inputProcessor->process(good);
        });
    }

private:
    std::vector<IInputProcessor<T> *> inputProcessors_;
};

/**
 * one input and one output worker
 */
template <typename From, typename To>
class Worker : public IInputProcessor<From>, public Convey<To>{};

#endif // __MiniFramework_h__
