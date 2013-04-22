/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */
#ifndef INCLUDE_sys_git_repository_h__
#define INCLUDE_sys_git_repository_h__

/**
 * @file git2/sys/repository.h
 * @brief Git repository custom implementation routines
 * @defgroup git_backend Git custom backend APIs
 * @ingroup Git
 * @{
 */
GIT_BEGIN_DECL

/**
 * Create a new repository with neither backends nor config object
 *
 * Note that this is only useful if you wish to associate the repository
 * with a non-filesystem-backed object database and config store.
 *
 * @param out The blank repository
 * @return 0 on success, or an error code
 */
GIT_EXTERN(int) git_repository_new(git_repository **out);

/**
 * Set the configuration file for this repository
 *
 * This configuration file will be used for all configuration
 * queries involving this repository.
 *
 * The repository will keep a reference to the config file;
 * the user must still free the config after setting it
 * to the repository, or it will leak.
 *
 * @param repo A repository object
 * @param config A Config object
 */
GIT_EXTERN(void) git_repository_set_config(git_repository *repo, git_config *config);

/**
 * Set the Object Database for this repository
 *
 * The ODB will be used for all object-related operations
 * involving this repository.
 *
 * The repository will keep a reference to the ODB; the user
 * must still free the ODB object after setting it to the
 * repository, or it will leak.
 *
 * @param repo A repository object
 * @param odb An ODB object
 */
GIT_EXTERN(void) git_repository_set_odb(git_repository *repo, git_odb *odb);

/**
 * Set the Reference Database Backend for this repository
 *
 * The refdb will be used for all reference related operations
 * involving this repository.
 *
 * The repository will keep a reference to the refdb; the user
 * must still free the refdb object after setting it to the
 * repository, or it will leak.
 *
 * @param repo A repository object
 * @param refdb An refdb object
 */
GIT_EXTERN(void) git_repository_set_refdb(git_repository *repo, git_refdb *refdb);

/**
 * Set the index file for this repository
 *
 * This index will be used for all index-related operations
 * involving this repository.
 *
 * The repository will keep a reference to the index file;
 * the user must still free the index after setting it
 * to the repository, or it will leak.
 *
 * @param repo A repository object
 * @param index An index object
 */
GIT_EXTERN(void) git_repository_set_index(git_repository *repo, git_index *index);

/** @} */
GIT_END_DECL
#endif