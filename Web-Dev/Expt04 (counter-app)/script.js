let count = 0;

let counterValue = document.querySelector('#counter-value');
let incrementBtn = document.querySelector('#inc-btn');
let decrementBtn = document.querySelector('#dec-btn');
let resetBtn = document.querySelector('#reset-btn');

incrementBtn.addEventListener('click', () => {
    count++;
    updateDisplay();
});

decrementBtn.addEventListener('click', () => {
    count--;
    updateDisplay();
});

resetBtn.addEventListener('click', () => {
    count = 0;
    updateDisplay();
});

function updateDisplay() {
    counterValue.textContent = count;
}