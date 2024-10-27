function updateStyle() {
    //get paragraph element
    const paragraph = document.getElementById('beowulfText');
    
    //get color input values
    const red = document.getElementById('R').value;
    const green = document.getElementById('G').value;
    const blue = document.getElementById('B').value;
    
    //get border width input value
    const borderWidth = document.getElementById('borderWidth').value;

    //update text color and border
    paragraph.style.color = `rgb(${red}, ${green}, ${blue})`;
    paragraph.style.borderColor = `rgb(${red}, ${green}, ${blue})`;
    paragraph.style.borderWidth = `${borderWidth}px`;
}

//add event listeners to change style when input values change
document.getElementById('R').addEventListener('input', updateStyle);
document.getElementById('G').addEventListener('input', updateStyle);
document.getElementById('B').addEventListener('input', updateStyle);
document.getElementById('borderWidth').addEventListener('input', updateStyle);