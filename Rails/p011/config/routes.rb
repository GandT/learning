Rails.application.routes.draw do
  resources :questionary_results
  resources :questionary_choices
  resources :questionary_items
  resources :questionaries
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
