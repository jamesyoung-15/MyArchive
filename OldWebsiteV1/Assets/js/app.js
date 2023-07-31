const navSlide = () => {
  const burger = document.querySelector(".burger");
  const nav = document.querySelector(".nav-link");
  const navLinks = document.querySelectorAll(".menu-item");
  const subMenu = document.querySelectorAll(".sub-menu");
  const hasSubMenu = document.querySelectorAll(".has-sub-menu");
  const subMenu2 = document.querySelectorAll(".sub-menu-2");
  const hasSubMenu2 = document.querySelectorAll(".has-sub-menu-2");

  //toggle nav
  burger.addEventListener("click", () => {
    nav.classList.toggle("nav-active");

    //animate links
    navLinks.forEach((link, index) => {
      if (link.style.animation) {
        link.style.animation = "";
      } else {
        link.style.animation = `navLinkFade 0.2s ease forwards ${
          index / 7 + 0.5
        }s`;
      }
    });

    //toggle burger into X
    burger.classList.toggle("toggle");

    //allow user to click into sub-menus
    for (let i = 0; i < hasSubMenu.length; i++) {
      hasSubMenu[i].addEventListener("click", function () {
        hasSubMenu[i].classList.toggle("on");
        subMenu[i].classList.toggle("display-block");
      });
    }

    for (let i = 0; i < hasSubMenu2.length; i++) {
      hasSubMenu2[i].addEventListener("click", function () {
        hasSubMenu2[i].classList.toggle("on");
        subMenu2[i].classList.toggle("display-block");
      });
    }
    window.addEventListener("scroll", () => {
      if (window.pageYOffset > 70) {
        nav.classList.add("nav-inactive");
      } else {
        nav.classList.remove("nav-inactive");
      }
    });
  });
};
//back to top button
const topButton = () => {
  const toTop = document.querySelector(".to-top");
  window.addEventListener("scroll", () => {
    if (window.pageYOffset > 700) {
      toTop.classList.add("to-top-active");
    } else {
      toTop.classList.remove("to-top-active");
    }
  });
};

navSlide();
topButton();
