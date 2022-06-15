function backgroundColorTransition() {

    let x = document.querySelector("body")
    x.classList.toggle('body-color-transition');

}

function transitionUpward() {
    let x = document.querySelector('.transition-upward')
    let y = document.querySelector('.loader')
    x.style.height = "100%"
    setTimeout(() => {
        y.style.height = "100px"
        y.style.display = "block"
    }, 500)

}

function bottomBar() {
    let bottomBar = document.querySelector('.bottom-bar')
    bottomBar.style.display = 'block'
    bottomBar.style.bottom = '20px'
}

function transitionClose() {
    let x = document.querySelector('.transition-upward')
    let y = document.querySelector('.loader')

    x.style.height = 0;

    y.style.display = "none"
    backgroundColorTransition();
    bottomBar()

}

function landingPageClose() {
    document.querySelector('.main').innerHTML = " ";
}


document.querySelector('.get-started').addEventListener('click', backgroundColorTransition);
document.querySelector('.get-started').addEventListener('click', function () { setTimeout(transitionUpward, 400) });
document.querySelector('.get-started').addEventListener('click', function () { setTimeout(transitionClose, 2000) });
document.querySelector('.get-started').addEventListener('click', function () { setTimeout(landingPageClose, 2000) });



function projects() {
    let main = document.querySelector('.main')
    main.innerHTML =

        `<i class="fa-solid fa-greater-than left"></i>        
                <article class="projects-container">
    <header class="main-header-one">

            <figure>
                    <img src="images/neogOne-cliQuizApp.png" alt="nodejs cli"
                            class="neogOne-cliQuizApp-image">
            </figure>

            <section class="project-description">

                    <h1>How well do you know me</h1>

                    <button class="live buttons">

                            <h3>live</h3>

                    </button>

                    <button class="source-code buttons">

                            <h3>source code</h3>

                    </button>
            </section>

    </header>
    <header class="main-header-two">

            <figure>
                    <img src="images/neogOne-cliQuizApp.png" alt="nodejs cli"
                            class="neogOne-cliQuizApp-image">
            </figure>

            <section class="project-description">

                    <h1>How well do you know me</h1>

                    <button class="live buttons">

                            <h3>live</h3>

                    </button>

                    <button class="source-code buttons">

                            <h3>source code</h3>

                    </button>
            </section>

    </header>
</article>
<i class="fa-solid fa-greater-than right"></i>
    `


    document.querySelector('.left').addEventListener('click', moveAside);
    document.querySelector('.right').addEventListener('click', moveAside1);


}
let icons = document.querySelectorAll('.icon')


icons[0].addEventListener('click', backgroundColorTransition);
icons[0].addEventListener('click', function () { setTimeout(transitionUpward, 400) });
icons[0].addEventListener('click', function () { setTimeout(transitionClose, 2000) });

icons[0].addEventListener('click', function () { setTimeout(projects, 2000) });

function moveAside1() {
    document.querySelector('.main-header-one').style.transform = 'translateX(0%)'
    document.querySelector('.main-header-two').style.transform = 'translateX(0%)'
}

function moveAside() {
    document.querySelector('.main-header-one').style.transform = 'translateX(-100%)'
    document.querySelector('.main-header-two').style.transform = 'translateX(-100%)'



}


