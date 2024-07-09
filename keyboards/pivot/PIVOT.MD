
make pivot/64_d2/f4:64keymap
make pivot/64_d2/l4:64keymap


name: CI
on: [ push ]

concurrency:
  group: ${{ github.workflow }}-${{ github.ref }}
  cancel-in-progress: true

env:
  REGEX_ANSI_COLOR: 's/\x1b\[[0-9;]*[mGKHF]//g'
  REGEX_MAKE_OUTPUT: '/^g*make\[1]: \(Enter\|Leav\)ing directory ''/d'

permissions: {}

jobs:
  build-vial:
    name: Build Vial keymaps
    runs-on: ubuntu-latest
    container: ghcr.io/qmk/qmk_cli

    steps:
    - name: checkout code
      uses: actions/checkout@v4
      with:
        submodules: recursive
        ref: vial001

    - name: Build with the Docker image
      run: |
        make pivot/64d2/f4:64keymap

    - uses: mr-smithers-excellent/docker-build-push@v6
      name: Build & push Docker image
      with:
        image: ${{ secrets.DOCKER_NAME }}/my-vialimage3
        registry: docker.io
        dockerfile: ./Dockerfile
        username: ${{ secrets.DOCKER_NAME }}
        password: ${{ secrets.DOCKER_PWD }}



        make pivot/64_d2/f4:64keymap && \
        make pivot/64_d2/l4:64keymap && \
        make pivot/67_d5/f4:64keymap && \
        make pivot/67_d5/l4:64keymap && \

