/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    val = init
    const obj = {
        increment(){
            return ++init
        },
        decrement(){
            return --init
        },
        reset(){
            return init=val
        }
    }
    return obj
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */