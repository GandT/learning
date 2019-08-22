require "calculator"

RSpec.describe Calculator do
    subject(:calc){ Calculator.new }
    it {
        # message expectation : logger.log
        logger = double("logger")
        expect(logger).to receive(:log)
        calc.log(logger)

        # この後に何か書けば「ある処理の前に特定の処理を呼ぶ」ができる
    }
end
