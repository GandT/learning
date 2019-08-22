require "calculator"

RSpec.describe Calculator do
    subject(:calc){ Calculator.new }

    # インスタンス変数としてのlet利用
    context "tax 5%" do
        # context内ローカル変数の宣言
        let(:tax){ 0.05 } 
        it { expect(calc.price(100, tax)).to eq(105) }
        it { expect(calc.price(100, tax)).to be_integer }
        it { expect(calc.price(298, tax)).to eq(312) }
        it { expect(calc.price(298, tax)).to be_integer }
    end
    context "tax 10%" do
        let(:tax){ 0.10 }
        it { expect(calc.price(100, tax)).to eq(110) }
        it { expect(calc.price(100, tax)).to be_integer }
        it { expect(calc.price(298, tax)).to eq(327) }
        it { expect(calc.price(298, tax)).to be_integer }
    end

    # letの遅延評価対策であるlet!
    context "tax 5%" do
        let!(:tax){ calc.tax = 0.05 } # !をつけると遅延評価にならない
        it { expect(calc.tax).to eq(0.05) }
        it { expect(calc.price(100)).to eq(105) }
    end
end
