require "calculator"

RSpec.describe Calculator do
    # describe == context
    context "when Normal Mode" do
        # it == example == specify
        it do
            @calc = Calculator.new
            expect(@calc.add(3, 8)).to eq(11)
        end
    end

    context "when Unlimited Mode" do
        specify "exceed the limit" do
        end
    end

    describe "自由な文字列" do
        example "とても自由な文字列" do
        end

        example "とても自由な保留"
    end
end
