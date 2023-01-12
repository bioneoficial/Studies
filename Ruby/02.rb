FAHRENHEIT = "Fahrenheit"
KELVIN = "Kelvin"
CELSIUS = "Celsius"
PRECISION = 2
class Temperature
	attr_reader :value, :unit
	def initialize value, unit
		@value = value
		@unit = unit
	end
	def inspect
		{ value: value, unit: unit }
	end
	def to_s
		"#{value}#{unit == CELSIUS ? "°C" : unit == KELVIN ? "K" :  "°F"}."
	end
end

class Celsius < Temperature
	def initialize value, unit = CELSIUS
		super value, unit
	end
	def to_fahrenheit
		Fahrenheit.new ((@value * 9 / 5) + 32).round(PRECISION)
	end
	def to_kelvin
		Kelvin.new (@value + 273.15).round(PRECISION)
	end
end

class Kelvin < Temperature
	def initialize value, unit = KELVIN
		super value, unit
	end
	def to_celsius
		Celsius.new (@value - 273.15).round(PRECISION)
	end
	def to_fahrenheit
		Fahrenheit.new ((@value - 273.15) * 9 / 5 + 32).round(PRECISION)
	end
end

class Fahrenheit < Temperature
	def initialize value, unit = FAHRENHEIT
		super value, unit
	end
	def to_celsius
		Celsius.new ((@value - 32) * 5 / 9).round(PRECISION)
	end
	def to_kelvin
		Kelvin.new ((@value - 32) * 5 / 9 + 273.15).round(PRECISION)
	end
end
