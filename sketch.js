//template function settings => instance
const template = ({color, biteSize, wave, speed}) => (p) => {

  p.setup = () => {
    p.createCanvas(200, 200);
  }

  p.draw = () => {
    p.background(0);
    p.fill(color)
    p.noStroke();

    let value = p[wave](p.frameCount * speed);
    if (wave === "sin") value = p.abs(value);


    let startAngle = biteSize * value;
    let endAngle = p.TWO_PI - startAngle; 

    p.arc(p.width / 2, p.height / 2, 80, 80, startAngle, endAngle, p.CHORD);
  };
};

const settings = [
    {color : "yellow", biteSize : Math.PI / 10, speed: 0.1, wave: "tan" },
    {color : "blue", biteSize: Math.PI / 10, speed: 0.05, wave: "sin"},
  ];
  
const cells = document.querySelectorAll(".cell");

cells.forEach((cell, i) => {
  new p5(template(settings[i % settings.length]), cell);
});

/*
function mySketch(p){
  p.setup = function(){
    p.createCanvas(100,100);
    p.describe('a yellow circle in convulsions')
  }

  p.draw = function (){
    p.background(0);
    p.noStroke();

    p.fill(255, 255, 0);

    let biteSize = p.PI / 10;
    let startAngle = biteSize * p.tan(p.frameCount * 0.1);
    let endAngle = p.TWO_PI - startAngle;

    p.arc(50, 50, 80, 80, startAngle, endAngle, p.CHORD);
  };
}

new p5(mySketch, "sketch");
*/