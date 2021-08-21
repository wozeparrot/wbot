// url: https://rosettacode.org/wiki/Category:Wren-queue
// source: https://rosettacode.org/mw/index.php?title=Category_talk:Wren-queue&action=edit&section=2
// file: queue
// name: Wren-queue
// author: PureFox
// license: MIT

/* Module "queue.wren" */

/* Queue represents a FIFO list of values. */
class Queue is Sequence {
     // Constructs a new empty queue.
    construct new() { _queue = [] }

    // Returns the number of elements in the queue.
    count { _queue.count }

    // Returns whether or not the queue is empty.
    isEmpty { count == 0 }

    // Removes all elements from the queue.
    clear() { _queue.clear() }

    // Returns the first item of the queue without removing it.
    // Returns null if the queue is empty.
    peek() { (!isEmpty) ? _queue[0] : null }
 
    // Adds 'item' to the queue and returns it.
    push(item) { _queue.add(item) }

    // Adds a sequence of 'items' (in order) to the queue and returns them.
    pushAll(items) {
        if (!(items is Sequence)) Fiber.abort("Argument must be a Sequence.")
        return _queue.addAll(items)
    }

    // Removes the first item from the queue and returns it.
    // Returns null if the queue is empty.
    pop() {
        var item = peek()
        if (item != null) {
            _queue.removeAt(0)
        }
        return item
    }

    // Copies the elements of the queue to a list and returns it.
    toList { _queue.toList }

    // Copies the elements of the queue to a new Queue object and returns it.
    copy() {
        var q = Queue.new()
        q.pushAll(_queue)
        return q
    }

    // Iterator protocol methods.
    iterate(iterator) { _queue.iterate(iterator) }
    iteratorValue(iterator) { _queue.iteratorValue(iterator) }

    // Returns the string representation of the queue's underlying list.
    toString { _queue.toString }
}