const HelloWorld = require("../build/Release/hello-world-native").HelloWorld;
const Fibonacci = require("../build/Release/hello-world-native").Fibonacci;
const assert = require("assert");

assert(HelloWorld, "The expected function is undefined");

function testBasic()
{
    const name = "Dante";
    const result =  HelloWorld(name);
    assert.strictEqual(result, `Hello ${name}`, "Unexpected value returned");
}

function testFibonacci() {
    assert.strictEqual(Fibonacci(0), 0, "Fib(0) should be 0")
    assert.strictEqual(Fibonacci(1), 1, "Fib(1) should be 1")
    assert.strictEqual(Fibonacci(2), 1, "Fib(2) should be 1")
    assert.strictEqual(Fibonacci(12), 144, "Fib(12) should be 144")
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");
assert.doesNotThrow(testFibonacci, undefined, "testFibonacci threw an expection");

console.log("Tests passed- everything looks OK!");