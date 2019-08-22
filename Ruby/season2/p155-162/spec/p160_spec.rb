require "calculator"

RSpec.describe Calculator do
    subject(:calc){ Calculator.new }
    it {
        # method stub による代役オブジェクト
        user = double("user")
        # user.name を設定
        allow(user).to receive(:name).and_return("tmp")

        expect(calc.add_by_user(3, 5, user.name)).to eq("#{user.name}「8」")
    }
end
