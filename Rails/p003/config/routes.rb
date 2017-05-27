Rails.application.routes.draw do
  get 'main/index'
  get 'main/redirect'
  get 'main', to: 'main#index'

  post 'main/index'
  post 'main', to: 'main#index'
end
