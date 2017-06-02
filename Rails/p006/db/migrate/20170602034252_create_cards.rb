class CreateCards < ActiveRecord::Migration[5.1]
  def change
    create_table :cards do |t|
      t.text :title
      t.text :author
      t.text :publisher
      t.integer :star
      t.text :memo

      t.timestamps
    end
  end
end
