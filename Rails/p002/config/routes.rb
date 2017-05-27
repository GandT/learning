Rails.application.routes.draw do
  # http://[ドメイン]/hello/index
  get "hello/index"

  # http://[ドメイン]/hello
  get "hello", to: "hello#index"
end