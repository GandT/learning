require "calculator"

RSpec.describe Calculator do
    it {
        expect(subject.add(3, 5)).to eq(8)
    }

    subject(:calc){ Calculator.new }
    it {
        expect(calc.add(3, 5)).to eq(8)
    }
end
