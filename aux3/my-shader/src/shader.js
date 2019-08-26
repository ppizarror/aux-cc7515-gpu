function Viewer() {

    let container;

    let camera, scene, renderer;

    let uniforms;

    let self = this;

    this.init = function () {

        container = document.getElementById('container');

        camera = new THREE.OrthographicCamera(-1, 1, 1, -1, 0, 1);

        scene = new THREE.Scene();

        let geometry = new THREE.PlaneBufferGeometry(2, 2);

        uniforms = {
            "time": {value: 1.0}
        };

        let material = new THREE.ShaderMaterial({

            uniforms: uniforms,
            vertexShader: document.getElementById('vertexShader').textContent,
            fragmentShader: document.getElementById('fragmentShader').textContent

        });

        let mesh = new THREE.Mesh(geometry, material);
        scene.add(mesh);

        renderer = new THREE.WebGLRenderer();
        renderer.setPixelRatio(window.devicePixelRatio);
        container.appendChild(renderer.domElement);

        this.onWindowResize();

        window.addEventListener('resize', this.onWindowResize, false);

    };

    this.onWindowResize = function () {

        renderer.setSize(window.innerWidth, window.innerHeight);

    };

    /**
     * FUncion que anima.
     *
     * @param {number=} timestamp
     */
    this.animate = function (timestamp) {

        requestAnimationFrame(self.animate); // REFERENCIA AL OBJETO, SUPER IMPORTANTE

        uniforms["time"].value = timestamp / 1000;

        renderer.render(scene, camera);

    }

}

let viewer = new Viewer();

viewer.init();
viewer.animate();