#ifndef __MiniFramework_h__
#define __MiniFramework_h__

#include <vector>
#include <algorithm>

template <typename V>
class IInputProcessor
{
public:
    /**
     * A pure virtual function intended to process the input of type V.
     * This function must be implemented by derived classes to handle specific input processing.
     * @param obj The input object of type V that needs to be processed.
     */
    virtual void process(const V& obj) = 0;
};


template <typename T>
class Convey
{
public:
    /**
     * Virtual destructor for the Convey class.
     * Ensures derived classes can clean up properly.
     */
    virtual ~Convey(void){}

    /**
     * Adds a new input processor to the convey mechanism.
     * This allows the convey to forward the goods to the next processor in the workflow.
     * @param inputProcessor A pointer to the input processor to be added to the convey mechanism.
     */
    void addNextProcessor(IInputProcessor<T> * inputProcessor ){
        inputProcessors_.push_back(inputProcessor);
    }

    /**
     * Propagates the given good through all added input processors.
     * Each input processor processes the good in the order they were added.
     * @param good The good to be propagated through the input processors.
     */
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
 * Represents a generic worker that can handle one type of input and produce another type of output.
 * Inherits from both IInputProcessor to process input and Convey to handle output propagation.
 */
template <typename From, typename To>
class Worker : public IInputProcessor<From>, public Convey<To>{};

#endif // __MiniFramework_h__



