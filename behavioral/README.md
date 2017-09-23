# Behavioral Patterns
Behavioral patterns are concerned with algorithms and the assignment of responsibilities between objects. Behavioral patterns describe not just patterns of objects or classes but also the patterns of communication between them. These patterns characterize complex control flow that's difficult to follow at run-time. They shift your focus away from flow of control to let you concentrate just on the way objects are interconnected.

## Chain of Responsibility
Avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it.

## Command
Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or long requests, and support undoable operations.

## Interpreter
Given a language, define a representation for its grammar along with an interpreter that uses the representation to interpret sentences in the language.

## Iterator
Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.

## Mediator
Define an object that encapsulates how a set of objects interact. Mediator promotes loose coupling by keeping objects from referring to each other explicitly, and its lets you vary their interaction independently.

## Memento
Without violating encapsulation, capture and externalize an object's internal state so that the object can be restored to this state later.

## Observer
Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

## State
Allow an object to alter its behavior when its internal state changes. The object will appear to change its classes.

## Strategy
Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it.

## Template Method
Define the skeleton of an algorithm in an operation, deferring some steps to subclasses. Template Method lets subclasses redefine certain steps of an algorithm without changing the algorithm's structure.

## Visitor
Represent an operation to be performed on the elements of an object structure. Visitor lets you define a new operation without changing the classes of the elements on which it operates.
