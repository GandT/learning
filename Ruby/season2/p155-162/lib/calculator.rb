class Calculator
    attr_accessor :tax
    def initialize(logger = nil)
        @tax = 0
    end

    def add(former, latter)
        # 二項を足す
        return former + latter
    end

    def add_by_user(former, latter, name)
        return "#{name}「#{former+latter}」"
    end

    def log(logger)
        logger.log
    end

    def sub(former, latter)
        return former - latter
    end

    def price(base, tax = @tax)
        return (base * (1+tax)).floor.to_i
    end
end