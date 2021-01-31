#include <napi.h>
#include <string>

using namespace Napi;

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  Napi::String name = info[0].As<Napi::String>();

  return Napi::String::New(env, "Hello " + static_cast<std::string>(name));
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "HelloWorld"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(addon, Init)
