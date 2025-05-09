let count = 0;
const counterValueElement = document.getElementById('counterValue');

function updateCounter() {
    counterValueElement.textContent = count;
}

function increase() {
    count++;
    updateCounter();
}

function decrease() {
    count--;
    updateCounter();
}

function reset() {
    count = 0;
    updateCounter();
}

// Initialize display
updateCounter();