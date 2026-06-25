# Contributing to RavenOS Umbra

Thank you for your interest in contributing to **RavenOS Umbra**.  
Umbra is built on the RavenLabs philosophy: clean architecture, modular subsystems, and developer‑friendly APIs.  
All contributions should follow these principles to keep the project consistent and maintainable.

This document explains how to contribute code, report issues, propose features, and collaborate with the team.

---

# Code of Conduct
By participating in this project, you agree to maintain a respectful, constructive environment.  
We welcome contributors of all skill levels.

---

# How to Contribute

## 1. Fork the Repository
Create your own fork of the project and clone it locally:

git clone https://github.com/<your-username>/RavenOS-Umbra.git

## 2. Create a Feature Branch
Use descriptive branch names:

Examples:
- `feature/new-menu-widget`
- `fix/display-refresh-bug`
- `docs/update-readme`

## 3. Follow the Architecture
Umbra is built from isolated subsystems:

- `raven_display.*` — Display Engine  
- `raven_input.*` — Input Engine  
- `raven_sound.*` — Sound Engine  
- `raven_ui.*` — UI Engine  

**Do not mix logic between subsystems.**  
Each module must remain self‑contained with its own `.h` and `.cpp`.

## 4. Coding Style
- Use clear, descriptive names  
- Keep functions small and focused  
- Document public APIs  
- Match the existing formatting style  
- Avoid unnecessary dependencies  
- Prefer composition over coupling  

If you add a new subsystem, follow the same structure as existing ones.

## 5. Document Your Changes
Every contribution must include:

- Updated comments in `.h` and `.cpp`  
- A new entry in `CHANGELOG.md`  
- A brief explanation in your pull request  

## 6. Submit a Pull Request
Push your branch and open a PR:
git push origin feature/my-feature
In your PR description, include:
- What you changed  
- Why you changed it  
- How to test it  
- Any known limitations  

We review PRs for clarity, architecture consistency, and maintainability.

---

# Reporting Issues

If you find a bug or want to request a feature, open an issue with:

- Clear title  
- Steps to reproduce (if applicable)  
- Expected behavior  
- Actual behavior  
- Hardware used (ESP32 model, display type, etc.)  

Screenshots or logs are helpful.

---

# Contributor Acknowledgments

### Core Contributors
- **Nyx (Zkyre‑Octane)** — Lead developer, architecture, UI/UX, subsystem design  
- **Jhocelynbogarin** — Early contributor, testing, feedback, asset desing  

If you contribute meaningfully, your name will be added here.

---

# Development Roadmap (High‑Level)
- Menu Engine  
- UI Navigation Loop  
- System Config Manager  
- Animation presets  
- Asset pipeline improvements  
- Extended widget library  

---

# Thank You
RavenOS Umbra is a passion project built with care.  
Every contribution — big or small — helps shape a better embedded OS.

If you have questions, ideas, or want to collaborate, feel free to open an issue or reach out.
