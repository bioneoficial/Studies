# Our hash
TURMA = { aluno01: [7.0, 3.0, 9.0],
          aluno02: [2.0, 5.0, 3.0],
          aluno03: [4.0, 5.0, 7.0],
          aluno04: [6.0, 5.0, 7.0],
          aluno05: [7.0, 7.0, 7.0],
          aluno06: [9.0, 5.0, 7.0],
          aluno07: [6.0, 6.0, 6.0],
          aluno08: [3.0, 5.0, 5.0],
          aluno09: [10.0, 10.0, 9.0],
          aluno10: [1.0, 4.0, 10.0],
          aluno11: [10.0, 7.0, 3.0],
          aluno12: [9.0, 8.0, 7.0],
          aluno13: [0.0, 2.0, 3.0],
          aluno14: [8.0, 3.0, 8.0],
          aluno15: [3.0, 8.0, 5.0],
          aluno16: [5.0, 6.0, 2.0],
          aluno17: [7.0, 3.0, 7.0],
          aluno18: [8.0, 7.0, 3.0],
          aluno19: [1.0, 5.0, 3.0],
          aluno20: [8.0, 5.0, 3.0] }
MEAN = 6.5
def mean(param)
  student_mean = []
  # here .each_with_object runs each function in each element creating a new object
  param.each_with_object({}) do |(student, grade), student_mean_grades|
    # here i save the student as index and his mean as value
    student_mean_grades[student] = grade.sum / grade.length
    # here i put this element in our array to use, because student_mean_grades will disappear in the 'do' scope(search for hoisting)
    student_mean << student_mean_grades
  end
end
def approved(param)
  # Select method, passing key as student and value as mean. Count method count N Elements in array
  # .to_f to the casting to float for the calc. .length will give us the total elements in our Hash
  # in the end we will return the percentage of approved students
  (param.select{|student, mean| mean >= MEAN}.count.to_f / param.length * 100.00)
end

total_mean = mean(TURMA)
approved = approved(total_mean)
puts "Total de #{TURMA.length} estudantes, onde #{approved}% dos estudantes foram aprovados."