Rails.application.routes.draw do
  get   'bbs/index'
  post  'bbs/index'
  get   'bbs', to: 'bbs#index'
  post  'bbs', to: 'bbs#index'

  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
