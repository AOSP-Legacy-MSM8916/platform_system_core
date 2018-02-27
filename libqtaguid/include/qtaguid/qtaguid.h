/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __LEGACY_QTAGUID_H
#define __LEGACY_QTAGUID_H

#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Set tags (and owning UIDs) for network sockets. The socket must be untagged
 * by calling qtaguid_untagSocket() before closing it, otherwise the qtaguid
 * module will keep a reference to it even after close.
 */
extern int legacy_tagSocket(int sockfd, int tag, uid_t uid);

/*
 * Untag a network socket before closing.
 */
extern int legacy_untagSocket(int sockfd);

/*
 * For the given uid, switch counter sets.
 * The kernel only keeps a limited number of sets.
 * 2 for now.
 */
extern int legacy_setCounterSet(int counterSetNum, uid_t uid);

/*
 * Delete all tag info that relates to the given tag an uid.
 * If the tag is 0, then ALL info about the uid is freeded.
 * The delete data also affects active tagged socketd, which are
 * then untagged.
 * The calling process can only operate on its own tags.
 * Unless it is part of the happy AID_NET_BW_ACCT group.
 * In which case it can clobber everything.
 */
extern int legacy_deleteTagData(int tag, uid_t uid);

#ifdef __cplusplus
}
#endif

#endif /* __LEGACY_QTAGUID_H */
