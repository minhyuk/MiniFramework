#ifndef __MiniFramework_h__
#define __MiniFramework_h__

#include &lt;vector&gt;
#include &lt;algorithm&gt;

template &lt;typename V&gt;
class IInputProcessor
{
public:
    /**
     * A pure virtual function intended to process the input of type V.
     * This function must be implemented by derived classes to handle specific input processing.
     * @param obj The input object of type V that needs to be processed.
     */
    virtual void process(const V&amp; obj) = 0;
};


template &lt;typename T&gt;
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
    void addNextProcessor(IInputProcessor&lt;T&gt; * inputProcessor ){
        /** 
         * Adds an input processor to the end of the processing chain.
         * The added processor will take part in the processing of the goods as they are propagated through the chain.
         */
        inputProcessors_.push_back(inputProcessor);
    }

    /**
     * Propagates the given good through all added input processors.
     * Each input processor processes the good in the order they were added.
     * @param good The good to be propagated through the input processors.
     */
    void propagate(const T&amp; good){
        /**
         * Iterates over all input processors added to this convey and calls their process function on the input good.
         * This supports a chain of responsibility pattern where each processor in turn does its part in handling the good.
         */
        typename std::vector&lt;IInputProcessor&lt;T&gt; *&gt;::iterator i;
        for(i = inputProcessors_.begin(); i!=inputProcessors_.end();++i){
            (*i)-&gt;process(good);
        }
    }

private:
    std::vector&lt;IInputProcessor&lt;T&gt; *&gt; inputProcessors_;
};

/**
 * Represents a generic worker that can handle one type of input and produce another type of output.
 * Inherits from both IInputProcessor to process input and Convey to handle output propagation.
 */
template &lt;typename From, typename To&gt;
class Worker : public IInputProcessor&lt;From&gt;, public Convey&lt;To&gt;{};

#endif // __MiniFramework_h__

