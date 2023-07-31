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

/* 3D Modelling Section */

//variables for setup

import * as THREE from "../node_modules/three/src/Three.js";
import { GLTFLoader } from "../node_modules/three/examples/jsm/loaders/GLTFLoader.js";

function init() {
  var container = document.querySelector(".comp-background");

  var scene = new THREE.Scene();
  var model;

  //camera
  var camera = new THREE.PerspectiveCamera(
    75,
    container.clientWidth / container.clientHeight,
    0.1,
    1000
  );

  //renderer
  var renderer = new THREE.WebGLRenderer({ antialias: true });
  renderer.setSize(container.clientWidth, container.clientHeight);
  renderer.setClearColor("#0a192f");
  document.body.appendChild(renderer.domElement);

  //responsive
  window.addEventListener("resize", () => {
    renderer.setSize(window.innerWidth, window.innerHeight);
    camera.aspect = window.innerWidth / window.innerHeight;

    camera.updateProjectionMatrix();
  });

  /*
  var geometry = new THREE.SphereGeometry(1, 10, 10);
  var material = new THREE.MeshLambertMaterial({ color: 0xffcc00 });
  var mesh = new THREE.Mesh(geometry, material);
  */

  var loader = new GLTFLoader();
  loader.load("../3DModels/computer.gltf", function (gltf) {
    model = gltf.scene;
    scene.add(model);
    animate();
  });
  camera.position.set(0, 1, 7);

  //cene.add(mesh);

  var light = new THREE.PointLight(0xffffff, 1, 500);
  light.position.set(10, 0, 25);
  scene.add(light);

  const ambient = new THREE.AmbientLight(0x404040, 3);
  scene.add(ambient);
  // var render = function () {
  //   requestAnimationFrame(render);
  //   renderer.render(scene, camera);
  // };
  // render();
  function animate() {
    requestAnimationFrame(animate);
    model.rotation.y += 0.005;
    renderer.render(scene, camera);
  }
}

init();
