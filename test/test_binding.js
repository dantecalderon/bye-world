const HelloWorld = require("../build/Release/hello-world-native").HelloWorld;
const assert = require("assert");

assert(HelloWorld, "The expected function is undefined");

function testBasic()
{
    const name = "Dante";
    const result =  HelloWorld(name);
    assert.strictEqual(result, `Hello ${name}`, "Unexpected value returned");
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

console.log("Tests passed- everything looks OK!");