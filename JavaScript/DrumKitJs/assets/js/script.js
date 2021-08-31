let comboBTN = document.querySelector('#comboBtn');
comboBTN.addEventListener('click', comboPlay);
let comboInput = document.querySelector('#combo');
comboInput.addEventListener('focus', inputFocus);
comboInput.addEventListener('blur', inputBlur);
const keys = Array.from(document.querySelectorAll('.key'));
keys.forEach(key => key.addEventListener('transitionend', removeTransition));

window.addEventListener('keydown', e => {
  const audio = document.querySelector(`audio[data-key="${e.key}"]`);
  const key = document.querySelector(`.key[data-key="${e.key}"]`);
  if (comboInput.className === 'onFocus' || !audio) {
    return;
  }
  key.classList.add('playing');
  audio.currentTime = 0;
  audio.play();
});

function inputFocus() {
  comboInput.className = 'onFocus';
}

function inputBlur() {
  comboInput.className = 'onBlur';
}

function removeTransition(e) {
  if (e.propertyName !== 'transform') return;
  e.target.classList.remove('playing');
}

function comboPlay() {
  var text = comboInput.value;
  var i = 0;
  (function myLoop() {
    var audio = document.querySelector(`audio[data-key="${text[i]}"]`);
    if(audio){
    let key = document.querySelector(`.key[data-key="${text[i]}"]`);
    setTimeout(function () {
      if (audio) {
        key.classList.add('playing');
        audio.currentTime = 0;
        audio.play();
      }
      if (i < text.length) {
        i++;
        myLoop();
      }
    }, 500);}else if( i < text.length) {
      i++;
      myLoop();
    }
  })(i);
}
