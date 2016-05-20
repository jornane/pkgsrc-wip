# $NetBSD$

BUILDLINK_TREE+=	uthash

.if !defined(UTHASH_BUILDLINK3_MK)
UTHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uthash+=	uthash>=1.9.8
BUILDLINK_PKGSRCDIR.uthash?=	../../local/uthash
BUILDLINK_DEPMETHOD.uthash?=	build
.endif	# UTHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-uthash
