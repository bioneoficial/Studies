
  let number, program, attempt, points, currentTemplate, templates, programCodeInput, programSelector, gameContainer, gameCodeDisplay, gameAttemptDisplay, pointsDisplay;

  document.addEventListener('DOMContentLoaded', function() {
    programCodeInput = document.getElementById('programCode');
    programSelector = document.getElementById('programSelector');
    gameContainer = document.getElementById('gameContainer');
    gameCodeDisplay = document.querySelector('.game__code');
    gameAttemptDisplay = document.querySelector('.game__attempt');
    pointsDisplay = document.getElementById('pointsDisplay');
    fetch('./result.json')
    .then(response => response.json())
    .then(data => {
      templates = data;
    })
    .catch(error => console.error('Error loading JSON:', error));

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
      playSound('startLevel');
    } else {
      alert("Invalid Program Number!");
    }
  }
  
  function play(response) {
    let correctAnswer = currentTemplate[number - 1];
    
    if (response === correctAnswer) {
      points += calculatePoints(attempt);
      number++;
      attempt = 1;
      playSound('soundCorrect'); 
    } else {
      if (attempt >= 3) {
        number++;
        attempt = 1;
      } else {
        attempt++;
      }
      playSound('soundWrong') 
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

    populateProgramSelector();
  }

  function populateProgramSelector() {
    programCodeInput.innerHTML = '<option value="">Select the Program</option>';
  
    templates.forEach(item => {
      let option = document.createElement('option');
      option.value = item.code;
      option.textContent = `Program ${item.code}`;
      programCodeInput.appendChild(option);
    });
  }
  
  fetch('./result.json')
  .then(response => response.json())
  .then(data => {
    templates = data;
    populateProgramSelector(); 
  })
  .catch(error => console.error('Error loading JSON:', error));
  
  function finishGame() {
    playSound('endGame');
    alert(`End of Game! Your score was: ${points}`);
    initialize();
  }

  function playSound(soundId) {
    const sound = document.getElementById(soundId);
    sound.play();
  }
  