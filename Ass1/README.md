# Epidemic Models Simulation

This repository contains a Python implementation of three common epidemiological models: **SI**, **SIR**, and a **Two-Factor Model**. These models simulate the spread of infectious diseases through a population using differential equations.

## **Models Overview**

### 1. **SI Model**
The SI (Susceptible-Infected) model divides the population into two compartments:
- **Susceptible (S):** Individuals who can be infected.
- **Infected (I):** Individuals who are infected and can spread the disease.

The rate of infection depends on the number of susceptible and infected individuals.

---

### 2. **SIR Model**
The SIR (Susceptible-Infected-Recovered) model expands on the SI model by adding a **Recovered (R)** compartment:
- **Susceptible (S):** Individuals who can be infected.
- **Infected (I):** Individuals who are infected and can spread the disease.
- **Recovered (R):** Individuals who have recovered and are immune to the disease.

The model includes a recovery rate (`gamma`) that moves individuals from the infected to the recovered compartment.

---

### 3. **Two-Factor Model**
This model introduces an additional **Exposed (E)** compartment to capture latent periods in disease progression:
- **Susceptible (S):** Individuals who can be infected.
- **Exposed (E):** Individuals who are infected but not yet infectious.
- **Infected (I):** Individuals who are actively infectious.

It accounts for:
- Birth and natural death rates (`mu`).
- Transition rates between compartments (`beta`, `etha`, `gamma`).

---

## **Features**
- **Numerical Simulation:** The models are solved iteratively using differential equations.
- **Visualization:** Each model's population dynamics are visualized over time using Matplotlib.
- **Parameter Customization:** Model parameters like infection rate (`beta`), recovery rate (`gamma`), and population size (`N`) are adjustable.

---

## **Dependencies**
This code requires the following Python libraries:
- `numpy`: For numerical computations.
- `matplotlib`: For plotting the results.

Install them using pip:
```bash
pip install numpy matplotlib
```

---

## **Usage**
1. Clone the repository:
   ```bash
   git clone https://github.com/YourUsername/EpidemicModels.git
   cd EpidemicModels
   ```

2. Run the script:
   ```bash
   python epidemic_models.py
   ```

3. Explore the dynamics of each model in the generated plots.

---

## **Output**
The code produces a set of three plots:
1. **SI Model:** Tracks Susceptible and Infected populations over time.
2. **SIR Model:** Tracks Susceptible, Infected, and Recovered populations over time.
3. **Two-Factor Model:** Tracks Susceptible, Exposed, and Infected populations over time.

---

## **Contributions**
Feel free to contribute by submitting pull requests to enhance the models, improve visualizations, or add new features.

---

## **License**
This project is open-source and available under the [MIT License](LICENSE).
