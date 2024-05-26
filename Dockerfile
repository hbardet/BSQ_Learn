# Utiliser l'image alpine comme base
FROM fedora

# Installer Python et les dépendances nécessaires
RUN dnf install python3 py3-pip make g++ gcc cargo go

# Créer le dossier /bsq dans le conteneur
RUN mkdir /bsq

# Copier tous les fichiers de l'hôte au dossier /bsq du conteneur
COPY . /bsq

# Définir le répertoire de travail à /bsq/scripts
WORKDIR /bsq/script

# Exécuter le script Python
CMD ["python3", "script_time_all_bsq.py"]

