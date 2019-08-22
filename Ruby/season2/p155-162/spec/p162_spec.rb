require "calculator"

RSpec.shared_examples "basic" do
    it "add" do
        @calc = Calculator.new
        expect(@calc.add(3, 8)).to eq(11)
    end
    it "sub" do
        @calc = Calculator.new
        expect(@calc.sub(8, 3)).to eq(5)
    end
end

RSpec.describe Calculator do
    context "Normal Mode" do
        include_examples "basic"
    end

    context "Unlimited Mode" do
        include_examples "basic"

        it "exceed" do
        end
    end
end
