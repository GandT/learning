Rails.application.routes.draw do
  get   'messages/index'
  get   'messages', to: 'messages#index'

  get 'messages/show'

  get   'messages/add'
  post  'messages/add', to: 'messages#create'

  get   'messages/edit/:id', to: 'messages#edit'
  patch 'messages/edit/:id', to: 'messages#update'

  get   'messages/delete/:id', to: 'messages#delete'

  get   'messages/:id', to: 'messages#show'

  get   'people/index'
  get   'people', to: "people#index"

  get   'people/add'
  post  'people/add', to: 'people#create'

  get   'people/edit/:id', to: 'people#edit'
  post  'people/edit/:id', to: 'people#update'
  patch 'people/edit/:id', to: 'people#update'

  get   'people/delete/:id', to: 'people#delete'

  get   'people/find'
  post  'people/find'

  get   'people/id'
  get   'people/:id', to: 'people#show'

  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
