const templates = [
    { code: "021", values: ['B', 'A', 'A', 'D', 'C', 'B', 'D', 'A', 'A', 'D', 'C', 'B', 'B', 'C', 'D', 'D', 'D', 'D', 'B', 'D', 'A', 'B', 'A', 'A', 'D', 'A', 'C', 'A', 'C', 'C'] },
    { code: "022", values: ['B', 'D', 'A', 'A', 'A', 'B', 'D', 'A', 'C', 'A', 'C', 'C', 'B', 'D', 'D', 'B', 'C', 'D', 'C', 'D', 'D', 'D', 'A', 'C', 'A', 'A', 'B', 'C', 'A', 'A'] },
    { code: "023", values: ['B', 'A', 'D', 'B', 'B', 'B', 'C', 'D', 'C', 'D', 'D', 'D', 'A', 'C', 'A', 'B', 'A', 'D', 'B', 'A', 'D', 'B', 'B', 'D', 'D', 'C', 'B', 'D', 'B', 'C'] },
    { code: "024", values: ['B', 'A', 'D', 'B', 'B', 'D', 'C', 'C', 'C', 'B', 'A', 'D', 'B', 'A', 'D', 'B', 'D', 'A', 'B', 'B', 'D', 'A', 'B', 'D', 'A', 'B', 'C', 'C', 'D', 'D'] },
    { code: "025", values: ['C', 'C', 'D', 'D', 'A', 'A', 'C', 'D', 'B', 'B', 'D', 'D', 'B', 'B', 'D', 'D', 'C', 'B', 'B', 'B', 'D', 'A', 'B', 'D', 'D', 'D', 'C', 'D', 'C', 'B'] },
  ];
  
  let number, program, attempt, points, currentTemplate;
  let programCodeInput, programSelector, gameContainer, gameCodeDisplay, gameAttemptDisplay, pointsDisplay;
  document.addEventListener('DOMContentLoaded', function() {
    programCodeInput = document.getElementById('programCode');
    programSelector = document.getElementById('programSelector');
    gameContainer = document.getElementById('gameContainer');
    gameCodeDisplay = document.querySelector('.game__code');
    gameAttemptDisplay = document.querySelector('.game__attempt');
    pointsDisplay = document.getElementById('pointsDisplay');
  
    const startButton = document.getElementById('startButton');
    const responseButtons = document.querySelectorAll('.game__button');
    const restartButton = document.querySelector('.game__restart');
  
    startButton.addEventListener('click', startGame);
    responseButtons.forEach(button => {
      button.addEventListener('click', function() {
        play(this.textContent);
      });
    });
    restartButton.addEventListener('click', initialize);
  
    initialize();
  });
  
  function startGame() {
    const programCode = programCodeInput.value;
    const foundProgram = templates.find(t => t.code === programCode);
  
    if (foundProgram) {
      currentTemplate = foundProgram.values;
      program = programCode;
      points = 0;
      number = 1;
      attempt = 1;
      programSelector.style.display = 'none';
      gameContainer.style.display = 'flex';
      updateDisplay();
    } else {
      alert("Invalid Program Number!\nType between 021 and 025!!!");
    }
  }
  
  function play(response) {
    let correctAnswer = currentTemplate[number - 1];
    
    if (response === correctAnswer) {
      points += calculatePoints(attempt);
      number++;
      attempt = 1;
    } else {
      if (attempt >= 3) {
        number++;
        attempt = 1;
      } else {
        attempt++;
      }
    }
    
    if (number > currentTemplate.length) {
      finishGame();
    } else {
      updateDisplay();
    }
  }
  
  function calculatePoints(attempt) {
    if (attempt === 1) return 3;
    if (attempt === 2) return 2;
    if (attempt === 3) return 1;
  }
  
  function updateDisplay() {
    gameCodeDisplay.textContent = `${program}->${number}:`;
    gameAttemptDisplay.innerHTML = `<b>Attempt ${attempt} of 3</b>`;
    pointsDisplay.textContent = `Points: ${points}`;
  }
  
  function initialize() {
    program = null;
    currentTemplate = []; 
    points = 0;
    number = 1;
    attempt = 1;
  
    gameCodeDisplay.textContent = '---'; 
    gameAttemptDisplay.innerHTML = '<b>Attempt 0 of 3</b>'; 
  
    programSelector.style.display = 'block';
    gameContainer.style.display = 'none';
  
    programCodeInput.value = '';
  }
  
  function finishGame() {
    alert(`End of Game! Your score was: ${points}`);
    initialize();
  }
  