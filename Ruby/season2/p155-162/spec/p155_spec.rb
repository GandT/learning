require "calculator"

RSpec.describe "A Calculator" do
    # 全ての example(it) 前に実行
    before(:example) do
        # テスト対象の作成
        @calc = Calculator.new
    end

    it "give 3 and 8, returns 11" do        
        # 期待する挙動の記述
        expect(@calc.add(3, 8)).to eq(11)
    end

    it "give 4 and 13, returns 17" do
        expect(@calc.add(4, 13)).to eq(17)
    end
end
