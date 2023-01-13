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
		"#{value} #{unit}."
	end
end

class Celsius < Temperature
	def initialize value
		super value, unit = "°C"
	end

	def to_fahrenheit
		Fahrenheit.new ((@value * 9 / 5) + 32)
	end

	def to_kelvin
		Kelvin.new (@value + 273.15)
	end

	def add temperature
		case temperature.unit
		when "°F"
			@value + temperature.to_celsius.value
		when "K"
			@value + temperature.to_celsius.value
		else
			@value + temperature.value
		end
	end

end

class Kelvin < Temperature
	def initialize value
		super value, unit = "K"
	end

	def to_celsius
		Celsius.new (@value - 273.15)
	end

	def to_fahrenheit
		Fahrenheit.new ((@value - 273.15) * 9 / 5 + 32)
	end

	def add temperature
		case temperature.unit
		when "°F"
			@value + temperature.to_kelvin.value
		when "°C"
			@value + temperature.to_kelvin.value
		else
			@value + temperature.value
		end
	end
end

class Fahrenheit < Temperature
	def initialize value
		super value, unit = "°F"
	end

	def to_celsius
		Celsius.new ((@value - 32) * 5 / 9)
	end

	def to_kelvin
		Kelvin.new ((@value - 32) * 5 / 9 + 273.15)
	end

	def add temperature
		case temperature.unit
		when "K"
			@value + temperature.to_fahrenheit.value
		when "°C"
			@value + temperature.to_fahrenheit.value
		else
			@value + temperature.value
		end
	end
end
