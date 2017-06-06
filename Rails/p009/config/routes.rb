Rails.application.routes.draw do
  # Scaffoldで用意された一括設定
  resources :mycontacts
=begin
　# 以下と等価
  get   '/mycontacts',      to: 'mycontacts#index'
  get   '/mycontacts/:id',  to: 'mycontacts#show'

  get   '/mycontacts/new',  to: 'mycontacts#new'
  post  '/mycontacts',      to: 'mycontacts#create'

  get   '/mycontacts/:id/edit',  to: 'mycontacts#edit'
  patch '/mycontacts/:id',       to: 'mycontacts#update'
  put   '/mycontacts/:id',       to: 'mycontacts#update'

  delete  '/mycontacts/:id',  to: 'mycontacts#destroy'
=end
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
