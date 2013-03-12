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
    	typename std::vector<IInputProcessor<T> *>::iterator i;
    	for(i = inputProcessors_.begin(); i!=inputProcessors_.end();++i){
    		(*i)->process(good);
    	}
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
