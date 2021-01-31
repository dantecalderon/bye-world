#include <napi.h>
#include <string>

using namespace Napi;

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::String name = info[0].As<Napi::String>();

  return Napi::String::New(env, "Hello " + static_cast<std::string>(name));
}

int32_t fib(int32_t x) {
  return x <= 1 ? x : fib(x - 1) + fib(x - 2);
}

Napi::Number Fibonacci(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Number n =  info[0].As<Number>();

  int32_t result = fib(static_cast<int32_t>(n));


  return Napi::Number::New(env, static_cast<double>(result));
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "HelloWorld"),
              Napi::Function::New(env, Method));
  exports.Set(Napi::String::New(env, "Fibonacci"),
              Napi::Function::New(env, Fibonacci));
  return exports;
}

NODE_API_MODULE(addon, Init)
