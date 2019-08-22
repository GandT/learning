require "calculator"

RSpec.describe Calculator do
    before(:example) do
        @calc = Calculator.new
    end

    it { expect(@calc.add(3, 5)).to eq(8) }
    it { expect(@calc.add(3, 5)).not_to eq(9) }
    it { expect(Calculator.name == "Calculator").to be true }
    it { expect(Calculator.class.name == "Calculator").to be false }
    it { expect(@calc.add(3, 5)).to be < 10 }
    it { expect(@calc.add(-4, +4)).to be_between(-4,+4).inclusive }
    it { expect(@calc).to respond_to(:sub) }
    it { expect(@calc.add(2, 3)).to be_integer }
end
