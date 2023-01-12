# frozen_string_literal: true
students = { :'Bione' => 6.9, :'The Joao' => 7.5, :'Carlos Henrique' => 9.8, :'Cicero Gabriel' => 4.4,
             :'Daniel Brasil' => 0.0, :'Igor Bruno' => 3.9, :'Julia Albuquerque' => 4.5, :'Lucas Oliveira'=> 8.9,
             :'Fabiana Bedreski' => 10.0, :'Miner' => 6.5}
def mean(param)
	total_grades = param.values
	total_grades.sum / param.length
end
def approved(param)
	((param.select { |name, grade| grade >= 6.5 }.length)* 100)  / (param.length)
	#https://www.rubyguides.com/2019/04/ruby-select-method/ select use
end
def reproved(param)
	((param.select { |name, grade| grade < 6.5 }.length) * 100) / (param.length)
end
mean = mean(students)
approved = approved(students)
reproved = reproved(students)
puts "Total de #{students.length} estudantes com media de turma de #{mean} onde #{approved}% dos estudantes
foram aprovados e #{reproved}% reprovados."
